#! /usr/bin/env python3
import numpy as np
from numpy import sin
from numpy import cos
from scipy.spatial.transform import Rotation as rot
from rotor_tm_traj import Optimization 
from rotor_tm_traj.Optimization.entire_path.generate_poly import generate_poly
import os 
from ament_index_python.packages import get_package_share_directory
from rotor_tm_msgs.msg import PositionCommand
from rotor_tm_utils import read_params


pkg_path = get_package_share_directory("rotor_tm_config")
payload_nmpc_params_path = os.path.join(pkg_path,"config","control_params/payload_nmpc_params.yaml")
read_params_funcs = read_params.read_params()
pl_nmpc_params = read_params_funcs.read_pl_nmpc_params(payload_nmpc_params_path)
Tf = pl_nmpc_params.Tf
N = pl_nmpc_params.N

class traj:
	def __init__(self,is_pl_nmpc = False):
		# for circles
		self.state_struct = {}
		self.Radius = None
		self.ramp_theta_coeff = None
		self.zcoeff = None
		self.tf = None
		self.last_pos = None
		self.offset_pos = None
		self.T = None 
		self.omega_des = None
		self.ramp_t = None
		self.ramp_dist = None
		self.circle_dist = None
		self.start = None
		self.duration = None

		# for line_quintic_traj_generator
		self.mapquad = None
		self.pathall = None
		self.coefficient = None
		self.finalpath = None
		self.timepoint = None
		self.timesegment = None

		# for min_snap_traj_generator
		self.snap_coeff = None
		self.snap_finalpath = None
		self.timelist = None
		self.polynomial_coeff = None
		self.traj_constant = None

		# check if the current traj has finished
		self.finished = False
		self.traj_type = 0
		self.is_pl_nmpc = is_pl_nmpc
		# 0 is flag for traj is not initialized
		# 1 is circle
		# 2 is line
		# 3 is min_snap

	def circle(self, t, init_pos = None, r = None, period = None, circle_duration = None):
		# CIRCLE trajectory generator for a circle
		
		if (np.all(init_pos!=None)) and (r != None) and (period != None) and (circle_duration != None):
			print('Generating Circular Trajectory ...')

			self.finished = False
			self.Radius = r
			self.offset_pos = np.array([init_pos[0]-self.Radius, init_pos[1], init_pos[2]])
			self.T = period
			self.omega_des = 2*np.pi/self.T
			self.alpha_des = np.pi/40
			self.start = init_pos
			self.ramp_t = self.omega_des/self.alpha_des
			self.duration = circle_duration

			thetainitial = np.array([[0.],[0],[0],[self.ramp_t*self.omega_des],[0],[0]])
			A = np.append(generate_poly(5,2,0), generate_poly(5,2,1), axis = 0)

			self.ramp_theta_coeff = np.matmul(np.linalg.inv(A), thetainitial)
			self.ramp_dist = sum(np.multiply(self.ramp_theta_coeff, np.array([[1],[1/2],[1/3],[1/4],[1/5],[1/6]])))
			self.circle_dist = self.omega_des*self.duration
			self.tf = self.ramp_t * 2 + self.duration
			self.traj_type = 1
		else:
			#print(type(t))
			#print(type(self.tf))
			self.pose_list = []
			t0 = t.nanoseconds / 1e9
			for j in range(N):
				message = PositionCommand()
				t_pred = t0 + j * Tf/ N
				if (t_pred) < self.tf:
					if t_pred <= self.ramp_t:  # ramping up the circle
						dt = t_pred /self.ramp_t
						integral_poly = generate_poly(6,0,dt)
						integral_poly = np.multiply(integral_poly[:,1:7],[1,1/2,1/3,1/4,1/5,1/6])
						polynominalmat = np.append(integral_poly, generate_poly(5,2,dt), axis=0)
						theta_d = np.matmul(polynominalmat, self.ramp_theta_coeff)
						theta_d = np.multiply(theta_d, np.array([[1],[1/self.ramp_t],[1/self.ramp_t**2],[1/self.ramp_t**3]]))
					else:
						if t_pred <=(self.ramp_t + self.duration): # constant velocity cruising
							dt = t_pred - self.ramp_t
							theta_d = np.zeros((4,1),dtype=float)
							theta_d[0] = self.omega_des * dt + self.ramp_dist
							theta_d[1] = self.omega_des

						else:  # ramping down the circle
							dt = 1 - (t_pred - self.duration - self.ramp_t)/self.ramp_t
							integral_poly = generate_poly(6,0,dt)
							integral_poly = np.multiply(integral_poly[:,1:7],[1,1/2,1/3,1/4,1/5,1/6])
							polynominalmat = np.append(integral_poly, generate_poly(5,2,dt), axis=0)

							theta_d = np.matmul(polynominalmat, self.ramp_theta_coeff)
							theta_d = np.multiply(theta_d, np.array([[1],[1/self.ramp_t],[1/self.ramp_t**2],[1/self.ramp_t**3]]))
							theta_d[0] = self.circle_dist + 2*self.ramp_dist - theta_d[0]

					x_pos = self.Radius * cos(theta_d[0])
					y_pos = self.Radius * sin(theta_d[0])
					x_vel = -self.Radius * sin(theta_d[0]) * theta_d[1]
					y_vel =  self.Radius * cos(theta_d[0]) * theta_d[1]
					x_acc = -self.Radius * cos(theta_d[0]) * theta_d[1]**2 - self.Radius * sin(theta_d[0]) * theta_d[2]
					y_acc = -self.Radius * sin(theta_d[0]) * theta_d[1]**2 + self.Radius * cos(theta_d[0]) * theta_d[2]
					x_jrk = self.Radius * sin(theta_d[0]) * theta_d[1]**3 - 3 * self.Radius * cos(theta_d[0]) * theta_d[1] * theta_d[2] - self.Radius * sin(theta_d[0]) * theta_d[3]
					y_jrk = -self.Radius * cos(theta_d[0]) * theta_d[1]**3 - 3 * self.Radius * sin(theta_d[0]) * theta_d[1] * theta_d[2] + self.Radius * cos(theta_d[0]) * theta_d[3]

					pos = self.offset_pos + np.array([x_pos[0], y_pos[0], 0]) 
					self.last_pos = pos 

					vel = np.array([x_vel[0], y_vel[0], 0.0])
					acc = np.array([x_acc[0], y_acc[0], 0.0])
					jrk = np.array([x_jrk[0], y_jrk[0], 0.0])
				else:
					pos = self.last_pos
					vel = np.array([[0.],[0],[0]])
					acc = np.array([[0.],[0],[0]])
					jrk = np.array([[0.],[0],[0]])
					self.finished = True

				self.state_struct["pos_des"] = pos
				self.state_struct["vel_des"] = vel.flatten()
				self.state_struct["acc_des"] = acc.flatten()
				self.state_struct["jrk_des"] = jrk.flatten()
				self.state_struct["quat_des"] = np.array([1.,0,0,0])
				self.state_struct["omega_des"] = np.array([0.,0,0])
				#message.header.stamp = now
				message.position.x = self.state_struct["pos_des"][0]
				message.position.y = self.state_struct["pos_des"][1]
				message.position.z = self.state_struct["pos_des"][2]
				message.velocity.x = self.state_struct["vel_des"][0]
				message.velocity.y = self.state_struct["vel_des"][1]
				message.velocity.z = self.state_struct["vel_des"][2]
				message.quaternion.w = self.state_struct["quat_des"][0]
				message.quaternion.x = self.state_struct["quat_des"][1]
				message.quaternion.y = self.state_struct["quat_des"][2]
				message.quaternion.z = self.state_struct["quat_des"][3]
				message.angular_velocity.x = self.state_struct["omega_des"][0]
				message.angular_velocity.y = self.state_struct["omega_des"][1]
				message.angular_velocity.z = self.state_struct["omega_des"][2]
				message.acceleration.x = self.state_struct["acc_des"][0]
				message.acceleration.y = self.state_struct["acc_des"][1]
				message.acceleration.z = self.state_struct["acc_des"][2]
				message.jerk.x = self.state_struct["jrk_des"][0]
				message.jerk.y = self.state_struct["jrk_des"][1]
				message.jerk.z = self.state_struct["jrk_des"][2]
				#print(type(self.current_traj.state_struct["quat_des"][0]))
				self.pose_list.append(message)
				

	def circlewithrotbody(self, t, init_pos = None, r = None, rangle = None, period = None, circle_duration = None):
		# CIRCLE trajectory generator for a circle
		
		if (np.all(init_pos!=None)) and (r != None) and (period != None) and (circle_duration != None):
			print('Generating Circular Trajectory ...')

			self.finished = False
			self.Radius = r
			self.offset_pos = np.array([init_pos[0]-self.Radius, init_pos[1], init_pos[2]])
			self.offset_euler = rot.from_quat(np.array([init_pos[4], init_pos[5], init_pos[6], init_pos[3]])).as_euler('ZYX')
			self.T = period
			self.omega_des = 2*np.pi/self.T
			self.alpha_des = np.pi/30
			self.start = init_pos
			self.ramp_t = self.omega_des/self.alpha_des
			self.duration = circle_duration
			self.angle_amp = rangle

			thetainitial = np.array([[0],[0],[0],[self.ramp_t*self.omega_des],[0],[0]])
			A = np.append(generate_poly(5,2,0), generate_poly(5,2,1), axis = 0)

			self.ramp_theta_coeff = np.matmul(np.linalg.inv(A), thetainitial)
			self.ramp_dist = sum(np.multiply(self.ramp_theta_coeff, np.array([[1],[1/2],[1/3],[1/4],[1/5],[1/6]])))
			self.circle_dist = self.omega_des*self.duration
			self.tf = self.ramp_t * 2 + self.duration
			self.traj_type = 2

		else:
			t = (t.nanoseconds / 1e9)
			if  t < self.tf:
				if t<=self.ramp_t:  # ramping up the circle
					dt = t/self.ramp_t
					integral_poly = generate_poly(6,0,dt)
					integral_poly = np.multiply(integral_poly[:,1:7],[1,1/2,1/3,1/4,1/5,1/6])
					polynominalmat = np.append(integral_poly, generate_poly(5,2,dt), axis=0)
					theta_d = np.matmul(polynominalmat, self.ramp_theta_coeff)
					theta_d = np.multiply(theta_d, np.array([[1],[1/self.ramp_t],[1/self.ramp_t**2],[1/self.ramp_t**3]]))
				else:
					if t<=(self.ramp_t + self.duration): # constant velocity cruising
						dt = t - self.ramp_t
						theta_d = np.zeros((4,1),dtype=float)
						theta_d[0] = self.omega_des * dt + self.ramp_dist
						theta_d[1] = self.omega_des

					else:  # ramping down the circle
						dt = 1 - (t - self.duration - self.ramp_t)/self.ramp_t
						integral_poly = generate_poly(6,0,dt)
						integral_poly = np.multiply(integral_poly[:,1:7],[1,1/2,1/3,1/4,1/5,1/6])
						polynominalmat = np.append(integral_poly, generate_poly(5,2,dt), axis=0)

						theta_d = np.matmul(polynominalmat, self.ramp_theta_coeff)
						theta_d = np.multiply(theta_d, np.array([[1],[1/self.ramp_t],[1/self.ramp_t**2],[1/self.ramp_t**3]]))
						theta_d[0] = self.circle_dist + 2*self.ramp_dist - theta_d[0]

				cos_t = cos(theta_d[0])
				sin_t = sin(theta_d[0])

				x_pos = self.Radius * cos_t
				y_pos = self.Radius * sin_t
				x_vel = -self.Radius * sin_t * theta_d[1]
				y_vel =  self.Radius * cos_t * theta_d[1]
				x_acc = -self.Radius * cos_t * theta_d[1]**2 - self.Radius * sin_t * theta_d[2]
				y_acc = -self.Radius * sin_t * theta_d[1]**2 + self.Radius * cos_t * theta_d[2]
				x_jrk =  self.Radius * sin_t * theta_d[1]**3 - 3 * self.Radius * cos_t * theta_d[1] * theta_d[2] - self.Radius * sin_t * theta_d[3]
				y_jrk = -self.Radius * cos_t * theta_d[1]**3 - 3 * self.Radius * sin_t * theta_d[1] * theta_d[2] + self.Radius * cos_t * theta_d[3]

				pos = self.offset_pos + np.array([x_pos[0], y_pos[0], 0]) 
				self.last_pos = pos 
				vel = np.array([x_vel[0], y_vel[0], 0.0])
				acc = np.array([x_acc[0], y_acc[0], 0.0])
				jrk = np.array([x_jrk[0], y_jrk[0], 0.0])

				# compute the desired roll pitch yaw
				cmd_roll =  self.angle_amp[0] * sin_t
				cmd_pitch = self.angle_amp[1] * sin_t
				cmd_yaw =   self.offset_euler[0] + self.angle_amp[2] * sin_t
				# print("The commended yaw is", cmd_yaw)

			    # compute the quaternion
				quat = rot.from_euler('ZYX', [cmd_yaw[0], cmd_pitch[0], cmd_roll[0]]).as_quat() 

				# reorder the quaternion
				quat = quat[[3,0,1,2]] 
				self.last_quat = quat
				# print("The commended quat is", quat)
				
				# compute the desired angular velocity
				angv = np.array([self.angle_amp[0] * (cos_t * theta_d[1]), self.angle_amp[1] * (cos_t * theta_d[1]), self.angle_amp[2] * (cos_t * theta_d[1])]) 

				# ang_vel_dot = np.array([rangle[0] * (-sin_t * theta_d[1]**2 + cos_t * theta_d[2]), rangle[1] * (-sin_t * theta_d[1]**2 + cos_t * theta_d[2]), rangle[2] * (-sin_t * theta_d[1]**2 + cos_t * theta_d[2])])

			else:
				pos = self.last_pos
				vel = np.zeros(3)
				acc = np.zeros(3)
				jrk = np.zeros(3)
				quat = self.last_quat
				angv = np.zeros(3)
				self.finished = True

			self.state_struct["pos_des"] = pos
			self.state_struct["vel_des"] = vel
			self.state_struct["acc_des"] = acc
			self.state_struct["jrk_des"] = jrk
			self.state_struct["quat_des"] = quat 
			self.state_struct["omega_des"] = angv

	def line_quintic_traj(self, t, map = None, path = None):

		# map is a class 
		# path is a 2D array
		if (np.any(map!= None) ) and (np.any(path != None)):
			print("Generating quintic trajectory")

			self.finished = False
			self.mapquad = map
			self.pathall = path
			pathqn = self.pathall
			ttotal = 10

			xy_res = map.resolution[0]
			basicdata = map.basicdata
			rowbasicdata = basicdata.shape[0]
			if rowbasicdata >= 2: 
				block = basicdata[1:rowbasicdata,:]
			else:
				block = np.array([])

			# use pathqn as the final path
			self.finalpath = pathqn

			pathlength = self.finalpath.shape[0]
			m = pathlength - 1

			distance = np.zeros((self.finalpath.shape[0],1))
			self.timesegment = np.zeros((self.finalpath.shape[0], 2))

			for i in range(1, m+1):
				previous = self.finalpath[i-1, :]
				afterward = self.finalpath[i, :]

				distance[i-1, :] = np.linalg.norm(afterward-previous)
				if distance[i-1,:]<=1:
					self.timesegment[i-1, 0] = distance[i-1,:]*5
					self.timesegment[i-1, 1] = 0
				else:
					self.timesegment[i-1, :] = np.sqrt(distance[i-1,:])*10
					self.timesegment[i-1, 1] = 0
			
			time_temp = 0
			self.timepoint = np.zeros((m, 1))
			for i in range(1, m+1):
				time_temp = time_temp + self.timesegment[i-1, 0]
				self.timepoint[i-1, 0] = time_temp
			self.timepoint = np.append(np.array([[0]]), self.timepoint, axis = 0)

			constraints = np.zeros((6*m, 6), dtype=float)
			condition = np.zeros((6*m, 3), dtype=float)
			self.coefficient = np.zeros((6*m, 3), dtype=float)
			for j in range(1, m+1):
				tstart = 0
				tend = self.timesegment[j-1, 0]

				constraints[6*j-6,:] = np.array([1, tstart, tstart**2, tstart**3  ,   tstart**4   ,  tstart**5])
				constraints[6*j-5,:] = np.array([0, 1     , 2*tstart, 3*tstart**2,   4*tstart**3 ,  5*tstart**4])
				constraints[6*j-4,:] = np.array([0, 0     , 2       , 6*tstart  ,   12*tstart**2,  20*tstart**3])
				constraints[6*j-3,:] = np.array([1, tend  , tend**2  , tend**3    ,   tend**4     ,  tend**5     ])
				constraints[6*j-2,:] = np.array([0, 1     , 2*tend  , 3*tend**2  ,   4*tend**3   ,  5*tend**4   ])
				constraints[6*j-1,:] = np.array([0, 0     , 2       , 6*tend    ,   12*tend**2  ,  20*tend**3  ])
				condition  [6*j-6,:] = self.finalpath[j-1,:]
				condition  [6*j-3,:] = self.finalpath[j,:]
				inverse = np.linalg.inv(constraints[6*j-6:6*j,0:6])
				coefficient_temp = np.matmul(inverse,condition[6*j-6:6*j,0:3])
				self.coefficient[6*j-6:6*j,0:3] = coefficient_temp
			self.traj_type = 3
		else:
				t = (t.nanoseconds / 1e9)
				lengthtime = self.timepoint.shape[0]				
				length = lengthtime -1 
				#length = 10 # prediction horizon 
				state = np.zeros((3, 3), dtype=float)		
				self.pose_list = []				

				if  self.is_pl_nmpc:
					message = PositionCommand()
					for i in range(1, length+1):
						if (t >= self.timepoint[i-1][0]) and (t < self.timepoint[i][0]) and (self.timesegment[i-1, 1] == 0):
							t0 = t
							for j in range(N):
								message = PositionCommand()
								#print("here")							
								t_pred = t0 + (j+1) * (Tf/N)
								currenttstart = self.timepoint[i-1][0] #t0 + j * (Tf/N)
								
								state = np.array([[1, (t_pred-currenttstart), (t_pred-currenttstart)**2, (t_pred-currenttstart)**3, (t_pred-currenttstart)**4, (t_pred-currenttstart)**5], [0, 1, 2*(t_pred-currenttstart), 3*(t_pred-currenttstart)**2, 4*(t_pred-currenttstart)**3, 5*(t_pred-currenttstart)**4], [0, 0, 2, 6*(t_pred-currenttstart), 12*(t_pred-currenttstart)**2, 20*(t_pred-currenttstart)**3]]) 
								state = np.matmul(state, self.coefficient[6*i-6:6*i,0:3])
								self.state_struct["pos_des"] = np.transpose(state[0,:]).flatten()
								self.state_struct["vel_des"] = np.transpose(state[1,:]).flatten()
								self.state_struct["acc_des"] = np.transpose(state[2,:]).flatten()
								self.state_struct["jrk_des"] = np.array([[0.],[0],[0]]).flatten()
								self.state_struct["quat_des"] = np.array([1.,0,0,0]).flatten()
								self.state_struct["omega_des"] = np.array([0.,0,0]).flatten()

								#message.header.stamp = now
								message.position.x = self.state_struct["pos_des"][0]
								message.position.y = self.state_struct["pos_des"][1]
								message.position.z = self.state_struct["pos_des"][2]
								message.velocity.x = self.state_struct["vel_des"][0]
								message.velocity.y = self.state_struct["vel_des"][1]
								message.velocity.z = self.state_struct["vel_des"][2]
								message.quaternion.w = self.state_struct["quat_des"][0]
								message.quaternion.x = self.state_struct["quat_des"][1]
								message.quaternion.y = self.state_struct["quat_des"][2]
								message.quaternion.z = self.state_struct["quat_des"][3]
								message.angular_velocity.x = self.state_struct["omega_des"][0]
								message.angular_velocity.y = self.state_struct["omega_des"][1]
								message.angular_velocity.z = self.state_struct["omega_des"][2]
								message.acceleration.x = self.state_struct["acc_des"][0]
								message.acceleration.y = self.state_struct["acc_des"][1]
								message.acceleration.z = self.state_struct["acc_des"][2]
								message.jerk.x = self.state_struct["jrk_des"][0]
								message.jerk.y = self.state_struct["jrk_des"][1]
								message.jerk.z = self.state_struct["jrk_des"][2]
								#print(type(self.current_traj.state_struct["quat_des"][0]))
								self.pose_list.append(message)
						
						elif (t >= self.timepoint[lengthtime-1]):
							message = PositionCommand()
							state[0, :] = self.finalpath[lengthtime - 1, :]
							state[1, :] = np.array([0,0,0])
							state[2, :] = np.array([0,0,0])
							self.finished = True	
							self.state_struct["pos_des"] = np.transpose(state[0,:])
							self.state_struct["vel_des"] = np.transpose(state[1,:])
							self.state_struct["acc_des"] = np.transpose(state[2,:])
							self.state_struct["jrk_des"] = np.array([[0.],[0],[0]]).flatten()
							self.state_struct["quat_des"] = np.array([1.,0,0,0]).flatten()
							self.state_struct["omega_des"] = np.array([0.,0,0]).flatten()
							message.position.x = self.state_struct["pos_des"][0]
							message.position.y = self.state_struct["pos_des"][1]
							message.position.z = self.state_struct["pos_des"][2]
							message.velocity.x = self.state_struct["vel_des"][0]
							message.velocity.y = self.state_struct["vel_des"][1]
							message.velocity.z = self.state_struct["vel_des"][2]
							message.quaternion.w = self.state_struct["quat_des"][0]
							message.quaternion.x = self.state_struct["quat_des"][1]
							message.quaternion.y = self.state_struct["quat_des"][2]
							message.quaternion.z = self.state_struct["quat_des"][3]
							message.angular_velocity.x = self.state_struct["omega_des"][0]
							message.angular_velocity.y = self.state_struct["omega_des"][1]
							message.angular_velocity.z = self.state_struct["omega_des"][2]
							message.acceleration.x = self.state_struct["acc_des"][0]
							message.acceleration.y = self.state_struct["acc_des"][1]
							message.acceleration.z = self.state_struct["acc_des"][2]
							message.jerk.x = self.state_struct["jrk_des"][0]
							message.jerk.y = self.state_struct["jrk_des"][1]
							message.jerk.z = self.state_struct["jrk_des"][2]
							self.pose_list.append(message)

				else:
					for i in range(1, length+1):
						if (t >= self.timepoint[i-1][0]) and (t < self.timepoint[i][0]) and (self.timesegment[i-1, 1] == 0):
							currenttstart = self.timepoint[i-1][0]
							state = np.array([[1, (t-currenttstart), (t-currenttstart)**2, (t-currenttstart)**3, (t-currenttstart)**4, (t-currenttstart)**5], [0, 1, 2*(t-currenttstart), 3*(t-currenttstart)**2, 4*(t-currenttstart)**3, 5*(t-currenttstart)**4], [0, 0, 2, 6*(t-currenttstart), 12*(t-currenttstart)**2, 20*(t-currenttstart)**3]]) 
							state = np.matmul(state, self.coefficient[6*i-6:6*i,0:3])
						elif (t >= self.timepoint[i-1]) and (t < self.timepoint[i]) and (self.timesegment[i-1, 1] == 1):
							state[0, :] = self.finalpath[i,:]
							state[1, :] = np.array([0,0,0])
							state[2, :] = np.array([0,0,0])
						elif (t >= self.timepoint[lengthtime-1]):
							state[0, :] = self.finalpath[lengthtime - 1, :]
							state[1, :] = np.array([0,0,0])
							state[2, :] = np.array([0,0,0])
							self.finished = True
					self.state_struct["pos_des"] = np.transpose(state[0,:])
					self.state_struct["vel_des"] = np.transpose(state[1,:])
					self.state_struct["acc_des"] = np.transpose(state[2,:])
					self.state_struct["jrk_des"] = np.array([[0.],[0],[0]]).flatten()
					self.state_struct["quat_des"] = np.array([1.,0,0,0]).flatten()
					self.state_struct["omega_des"] = np.array([0.,0,0]).flatten()
					

		

	def min_snap_traj_generator(self, t_current, path = None, options = None):
		
		if (np.any(path!= None) ) and (np.any(options != None)):
			print("The path is ", path)

			self.finished = False
			self.pathall = path
			self.finalpath = path
			self.traj_constant = options

			if (self.traj_constant.pt_num-1 > self.traj_constant.total_traj_num):
				self.traj_constant.pt_num = self.traj_constant.total_traj_num + 1

			self.traj_constant.traj_num = self.traj_constant.pt_num -1
			self.polynomial_coeff = generate_poly_coeff(self.traj_constant)
			
			# optimization
			T_seg_c = allocate_time(path,self.traj_constant.max_vel,self.traj_constant.max_acc)
			self.coefficient, self.timelist = optimize_traj(path, self.traj_constant, T_seg_c, self.traj_constant.cor_constraint)
			
			print("The total traj num is ", self.traj_constant.total_traj_num)
			self.traj_type = 4

		else:
			for i in range(self.traj_constant.total_traj_num):
				if (self.traj_constant.pt_num == 2) or ((i+1)%(self.traj_constant.pt_num-1) == 1):
					t_start = self.timelist[i,0]
				
				if (t_current >= self.timelist[i,0]) and (t_current < self.timelist[i+1,0]):
					
					time_term = t_current - t_start
					time_matrix = generate_polynomial_matrix(self.traj_constant.max_exponent,3,time_term)
					state = np.matmul(np.multiply(self.polynomial_coeff[0:4,:], time_matrix), self.coefficient[:,i*self.traj_constant.dim:(i+1)*self.traj_constant.dim])
					
				elif t_current >= self.timelist[self.traj_constant.total_traj_num]:
					
					state = np.zeros((4, 3), dtype=float)
					state[0,:] = self.finalpath[self.traj_constant.total_traj_num:self.traj_constant.total_traj_num+1,:]
					state[1,:] = np.array([[0,0,0]])
					state[2,:] = np.array([[0,0,0]])
					state[3,:] = np.array([[0,0,0]])
					self.finished = True

			self.state_struct["pos_des"] = np.transpose(state[0,:])
			self.state_struct["vel_des"] = np.transpose(state[1,:])
			self.state_struct["acc_des"] = np.transpose(state[2,:])
			self.state_struct["jrk_des"] = np.transpose(state[3,:])
			self.state_struct["quat_des"] = np.array([1,0,0,0])
			self.state_struct["omega_des"] = np.array([0,0,0])

	def step_des(self, t, des_pose = None):
		if (np.any(des_pose!= None)):
			self.step_des_pose = des_pose
			self.finished = False
			self.traj_type = 5
		else:
			if ((t.nanoseconds / 1e9) >= 10): 
				print("The t in step_des is ", t)
				self.finished = True

			self.state_struct["pos_des"] = self.step_des_pose[0:3] 
			self.state_struct["vel_des"] = np.zeros(3)
			self.state_struct["acc_des"] = np.zeros(3)
			self.state_struct["jrk_des"] = np.zeros(3) 
			self.state_struct["quat_des"] = self.step_des_pose[3:7]
			self.state_struct["omega_des"] = np.array([0,0,0])
			
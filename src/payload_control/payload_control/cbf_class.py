import numpy as np
from dataclasses import dataclass
import os
import sys
from utils import vec2asym
from numpy import linalg as LA
import matplotlib.pyplot as plt
import time
import yaml
import casadi as ca
import ipdb
from rotor_tm_utils import read_params

import plotly.graph_objects as go
from scipy.spatial import HalfspaceIntersection, ConvexHull
from scipy.optimize import linprog

N =10

@dataclass
class Obstacles:
  obstacles:list


def plot_polytope_3d(A, B):
    # Ensure A and B are numpy arrays
    A = np.asarray(A)
    B = np.asarray(B).flatten()  # Ensure B is a 1D array

    # Find a feasible point inside the polytope using linear programming
    c = np.zeros(A.shape[1])  # Objective: Minimize 0 (just find a feasible point)
    res = linprog(c, A_ub=A, b_ub=B, method="highs")  # Add small buffer

    if res.status != 0:
        raise ValueError("No feasible point found for the given constraints.")

    feasible_point = res.x + 1e-3  # Slightly nudge inside

    # Convert to half-space representation
    hs = np.hstack((A, -B.reshape(-1, 1)))

    # Compute intersections of half-spaces
    hs_intersection = HalfspaceIntersection(hs, feasible_point)
    vertices = hs_intersection.intersections

    # Compute convex hull of intersection points
    hull = ConvexHull(vertices)

    # Create 3D plot
    fig = go.Figure()

    # Add convex hull faces
    fig.add_trace(go.Mesh3d(
        x=vertices[:, 0], y=vertices[:, 1], z=vertices[:, 2],
        i=hull.simplices[:, 0], 
        j=hull.simplices[:, 1], 
        k=hull.simplices[:, 2],
        color='cyan', opacity=0.5
    ))

    fig.update_layout(title="3D Polytope Visualization",
                      scene=dict(xaxis_title='X', yaxis_title='Y', zaxis_title='Z'))
    fig.show()







#Create an Obstacle class
class Obs:
    def __init__(self,origin_x, origin_y,origin_z, length,breadth,height):
        self.origin_x = origin_x
        self.origin_y = origin_y
        self.origin_z = origin_z
        self.length = length
        self.breadth = breadth
        self.height = height
    
    def get_convex_rep(self):
        # World coordinates
        A = np.array([[0,0,1],     #Positive z
                      [0,0,-1],    #Negative z 
                      [1,0,0],     #Positive x
                      [-1,0,0],    #Negative x
                      [0,1,0],     #Positive y
                      [0,-1,0]])   #Negative y
        # AX<=B
        # AX>=B or -AX<=-B
        B = np.array([[self.origin_z + self.height], 
                      [self.origin_z],
                      [self.origin_x + self.length],
                      [-self.origin_x],
                      [self.origin_y + self.breadth],
                      [-self.origin_y]])
        return (A,B)

# Create a Triangulalr payload class
class TriangleObs:
    def __init__(self,rho_vect_list):
        # Assuming each row of the rho_vec_list is (x,y,z)
        self.rho_vec_list = rho_vect_list
        # rho_vect_list = np.array([[-0.288, 0.5, 0.01812],
        #                                 [ 0.577,    0. ,      0.01812],
        #                                 [-0.288 ,  -0.5      ,0.01812]]).T
        print("Rho Vector:", self.rho_vec_list)
        self.P1 = np.array(rho_vect_list[:,0]).reshape(3,1)
        self.P2 = np.array(rho_vect_list[:,1]).reshape(3,1)
        self.P3 = np.array(rho_vect_list[:,2]).reshape(3,1)

        z = rho_vect_list[2,0]
        self.P1_hat = np.reshape(np.array(rho_vect_list[:,0])-np.array([0,0,-z]),(3,1))
        self.P2_hat = np.reshape(np.array(rho_vect_list[:,1])-np.array([0,0,-z]),(3,1))
        self.P3_hat = np.reshape(np.array(rho_vect_list[:,2])-np.array([0,0,-z]),(3,1))

    def get_convex_rep(self):
        # AI,BI = self.calculateAB(self.P1,self.P2,self.P3)
        # AII,BII = self.calculateAB(self.P1_hat,self.P3_hat,self.P2_hat)
        # AIII,BIII = self.calculateAB(self.P1,self.P2_hat,self.P2)
        # AIV,BIV = self.calculateAB(self.P2,self.P3_hat,self.P3)
        # AV,BV = self.calculateAB(self.P3,self.P1_hat,self.P1)
        # A = np.vstack([AI,AII,AIII,AIV,AV])
        # B = np.vstack([BI,BII,BIII,BIV,BV])
        # return A,B
        A = np.array([[0,0,1],     #Positive z
                      [0,0,-1],    #Negative z 
                      [0.267,0.462,0],     #Positive x
                      [0.267,-0.462,0],    #Negative x
                      [-1,0,0]])   #Negative y
        # AX<=B
        # AX>=B or -AX<=-B
        B = np.array([[0.01125], 
                      [0.0],
                      [0.267*0.3083],
                      [0.267*0.3083],
                      [0.154]])
        return A,B

    # @staticmethod
    # def calculateAB(P1,P2,P3):
    #     # shape of A should be (1,3)
    #     A = np.cross(P2.T-P1.T,P3.T-P1.T).reshape(1,3)
    #     # B should be a scalar
    #     #(1,3)x(3,1) = scalar
    #     B = A@P1
    #     return A,B.item()

class CBFDualityOptimization:
    def __init__(self,payload_params,obstacle_params, model_p):
        # Determine the number of quadrotors
        self.robot_num = payload_params.nquad
        # extract the obstacles from the file
        self.obstacles = []
        self.n_obs = len(obstacle_params.keys())
        for i in range(self.n_obs):
            wall = obstacle_params["wall" + str(i+1)]
            # Obtain the obstacle polytopes
            self.obstacles.append(Obs(wall['x'],wall['y'],wall['z'],wall['l'],wall['b'],wall['h']))
        # Obtain the payload polytope
        self.payload = TriangleObs(payload_params.rho_vec_list)
        # Obtain the quadrotor polytopes
        self.quad = []
        for i in range(self.robot_num):
            self.quad.append(Obs(0, 0, 0,0.15,0.15,payload_params.cable_length[i]))
        self.state = np.array([0]*13)
        self.variables = dict()
        self.inv_P = payload_params.pseudo_inv_P
        self.rho_vec_list = payload_params.rho_vec_list.T
        self.params = payload_params
        self.warm_start = {}
        self.gamma = model_p[-1]
        self.cbf_p = model_p[-1-self.n_obs-(self.n_obs*self.robot_num)-self.robot_num:-1]
        self.hlist = []
        self.hlist_lb = np.empty(0)
        self.hlist_ub = np.empty(0)
    
    def deriv(self,X,U):
        #payload params
        m = self.params.mass
        g = self.params.grav
        I_load = self.params.I                           #intertia
        M_load = m * np.eye((3))                    #mass distribution

        #inertial 
        e3 = ca.vertcat(0,0,1)
        
        # force and moment
        F = U[0:3]
        M = U[3:6]
        
        # velocity, quat, omega
        vel = X[3:6]
        qw = X[6]
        qx = X[7]
        qy = X[8]
        qz = X[9]
        quat = ca.vertcat(qw,qx,qy,qz)
        p = X[10]
        q = X[11]
        r = X[12]
        omega = ca.vertcat(p,q,r)

        # system dynamics
        # angular velocity
        K_quat = 2                                                          #this enforces the magnitude 1 constraint for the quaternion
        quaterror = 1 - (qw**2 + qx**2 + qy**2 + qz**2)                     #norm_2(quat) 
        a_matrix = ca.vertcat(ca.horzcat(0,- p,- q,- r),
                              ca.horzcat(p,0,r,-q),
                              ca.horzcat(q,-r,0,p),
                              ca.horzcat(r,q,-p,0))
    
        quat_dt = 1/2 *ca.mtimes(a_matrix, quat) + K_quat * ca.mtimes(quaterror, quat)

        #Inerttia and other forces     
        cc_forces = ca.cross(omega, ca.mtimes(I_load, omega))               #colaris and centripetel forces 
        # xdot
        fexpl = ca.vertcat(vel,
                           ca.mtimes(np.linalg.inv(M_load) ,(F - m * g * e3)),
                           quat_dt,
                           ca.mtimes(np.linalg.inv(I_load), (M - cc_forces))
                           )
        return fexpl

    # discretization using RK4 method
    def dynamics_opt(self,X,U,DT=0.01):
        for j in range(1):
            k1 = self.deriv(X, U)
            k2 = self.deriv(X + DT/2 * k1, U)
            k3 = self.deriv(X + DT/2 * k2, U)
            k4 = self.deriv(X + DT * k3, U)
            X_next=X+DT/6*(k1 +2*k2 +2*k3 +k4)
        return X_next
    
    #optimization to find minimum distance between 3D polytopes
    def get_minimum_dist(self,obs_A,obs_B,robot_A,robot_B):    
        # Create two variables point1 and point2
        point1 = ca.SX.sym("point1",obs_A.shape[-1],1)
        point2 = ca.SX.sym("point2",robot_A.shape[-1],1)
        
        x = ca.vertcat(point1, point2)
        
        # point1 = opti.variable(obs_A.shape[-1],1)
        # point2 = opti.variable(robot_A.shape[-1],1)
        cost=0
        # Add the cost function to the optimization problem
        dist_vec = point1-point2
        cost = dist_vec.T@dist_vec
        # Specify the constraints
        # const1 = obs_A@point1<=obs_B
        # const2 = robot_A@point2<=robot_B
        # g.append(obs_A@point1-obs_B)
        # lbg.append(-ca.inf)
        # ubg.append(0)
        # g.append(robot_A@point2-robot_B)
        # lbg.append(-ca.inf)
        # ubg.append(0)
        # Optimization variable
        # opti = ca.Opti()

        # print("Obstacle A", obs_A)
        # print("Obstacle B", obs_B)
        # print("Robot A", robot_A)
        # print("Robot B", robot_B)

        g = ca.vertcat(ca.mtimes(obs_A, point1) - obs_B,
                        ca.mtimes(robot_A, point2) - robot_B)
        nlp = {}
        nlp["f"] = cost
        nlp["g"] = g
        nlp["x"] = x
        option = {"verbose": False, "ipopt.print_level": 5, "print_time": 0}
        solver = ca.nlpsol("solver","ipopt",nlp,option)

        sol = solver(lbg=-ca.inf,ubg=0)
        
        opt_x = sol["x"]
        opt_dist = ca.sqrt(sol["f"])
        lamb_g = sol["lam_g"]
        print("lam G", lamb_g)

        lamb = lamb_g[:obs_A.shape[0]]
        mu = lamb_g[obs_A.shape[0]:]
        # Add the constraint to the optimization problem
        # opti.subject_to(const1)
        # opti.subject_to(const2)
        
        # opti.minimize(cost)
        # Add solver options
        # option = {"verbose": False, "ipopt.print_level": 0, "print_time": 0}
        # opti.solver("ipopt",option)
        # Solve the optimization problem
        # opt_sol = opti.solve()
        # Get the minimum distance
        # dist = opt_sol.value(ca.norm_2(dist_vec))
        # Check if the distance is positive
        if opt_dist>0:
            lamb = lamb/2*opt_dist
            mu   = mu/2*opt_dist
            
        else:
            opt_dist=-1
            lamb = np.zeros(shape = (obs_A.shape[0],))
            mu   = np.zeros(shape = (robot_A.shape[0],))
        
        print("Min Dist: ", opt_dist)
        print("Lambda" , lamb)
        print("Mu" , mu)

        return opt_dist,lamb,mu
    
    #optimization to find minimum distance between 3D polytopes
    def get_all_minimum_dist(self,cbf_params):   
        len_lambda    = cbf_params["lambda"]
        len_mu        = cbf_params["mu"]
        obs_pl_len    = (len_lambda + len_mu + 1)*self.n_obs
        obs_quad_len  = (len_lambda + len_lambda + 1)*self.n_obs*self.robot_num
        quad_quad_len = (len_lambda + len_lambda + 1)*self.robot_num
        model_u       = np.zeros((obs_pl_len + obs_quad_len + quad_quad_len,1)) 
        omega_curr    = 0.1
        length_cbf_p  = self.n_obs + (self.n_obs*self.robot_num) + self.robot_num
        cbf_p         = [None]*length_cbf_p
        
        ##### Payload Obstacle #####
        for i,obs in enumerate(self.obstacles):
            mat_A, vec_b     = obs.get_convex_rep()
            robot_G, robot_g = self.payload.get_convex_rep()
            
            ################################################
            # mat_A = mat_A/vec_b
            # vec_b = vec_b/vec_b

            # robot_G = robot_G/robot_g
            # robot_g= robot_g/robot_g
            ################################################
            print("In the local frame")
            print("Obstacle A", mat_A)
            print("Obstacle B", vec_b)
            print("Robot A", robot_G)
            print("Robot B", robot_g)
            print("In the word frame:")
            print("Obstacle A", mat_A)
            print("Obstacle B", vec_b)
            print("Robot A", np.dot(robot_G, self.get_rotation_state(self.state,False,False).T))
            print("Robot B", np.dot(np.dot(robot_G, self.get_rotation_state(self.state,False,False).T), self.transtion_state()) + robot_g)

            # plot_polytope_3d(robot_G, robot_g)
            # plot_polytope_3d(mat_A, vec_b)

            # get current value of cbf
            cbf_curr, lamb_curr, mu_curr = self.get_minimum_dist(
                mat_A,
                vec_b,
                np.dot(robot_G, self.get_rotation_state(self.state,False,False).T),
                np.dot(np.dot(robot_G, self.get_rotation_state(self.state,False,False).T), self.transtion_state()) + robot_g,
            )

            cbf_p[i] = cbf_curr
            # Initialize lambda mu and omega input values
            model_u[(len_lambda + len_mu + 1)*i:(len_lambda + len_mu + 1)*i+len_lambda]                       = lamb_curr
            model_u[(len_lambda + len_mu + 1)*i+len_lambda:(len_lambda + len_mu + 1)*i + len_lambda + len_mu] = mu_curr
            model_u[(len_lambda + len_mu + 1)*(i+1)-1]                                                        = omega_curr
        
        ####
        print("Current state value:" , self.state)
        poses = self.calculateCableDir(self.state,self.input,False)
        
        ##### Quadrotor Obstacle #####
        st_val = (len_lambda + len_mu + 1)*self.n_obs + i*self.robot_num*(len_lambda + len_lambda + 1)
        for i,obs in enumerate(self.obstacles):
            for quad_no in range(len(self.quad)):
                mat_A, vec_b = obs.get_convex_rep()
                robot_G, robot_g = self.quad[quad_no].get_convex_rep()
                #print("A= ",robot_G,"B= ",robot_g)
                Rwb = self.get_rotation_state(self.state,False,False)
                # get current value of cbf
                pose = poses[quad_no]
                x,y,z = pose[0],pose[1],pose[2]

                print("x: ",x)
                print("y", y)
                print("z", z)
                pos_mag = (x**2+y**2+z**2)**0.5
                x/=pos_mag
                y/=pos_mag
                z/=pos_mag

                print("x after: ", x)
                print("y after: ", y)
                print("z after: ", z)

                offset = ca.SX(3,1)
                offset[0] = x/2
                offset[1] = y/2
                offset[2] = z/2
                
                Rbox = self.get_Rotation_Of_StringBox(pose,False)

                Tbox = np.array(self.state[0:3]).T + Rwb@(self.rho_vec_list[quad_no]).T + np.array(self.params.cable_length).T*np.array([x/2,y/2,z/2]).T

                Tbox = Tbox.reshape(3,1)

                print("RBox: ",Rbox)
                print("TBox: ", Tbox)
                cbf_curr, lamb_curr, mu_curr = self.get_minimum_dist(
                    mat_A,
                    vec_b,
                    np.dot(robot_G, Rbox.T),
                    np.dot(np.dot(robot_G, Rbox.T), Tbox) + robot_g,
                )
                cbf_p[self.n_obs + i*self.robot_num + quad_no] = cbf_curr
                # Initialize lambda mu and omega input values
                model_u[st_val + (len_lambda + len_lambda + 1)*quad_no:st_val + (len_lambda + len_lambda + 1)*quad_no+len_lambda]                           = lamb_curr.reshape((len_lambda,1))
                model_u[st_val + (len_lambda + len_lambda + 1)*quad_no+len_lambda:st_val + (len_lambda + len_lambda + 1)*quad_no + len_lambda + len_lambda] = mu_curr.reshape((len_lambda,1))
                model_u[st_val + (len_lambda + len_lambda + 1)*(quad_no+1)-1]                                                                               = omega_curr


        quad_rep = []
        st_val = (len_lambda + len_mu + 1)*self.n_obs + self.n_obs*self.robot_num*(len_lambda + len_lambda + 1)
        for quad_no in range(len(self.quad)):
            quad_rep.append(self.getQuadRepresentation(poses,self.rho_vec_list,quad_no,False))
        for quad_no in range(len(self.quad)):
            Ai,Bi =  quad_rep[quad_no]
            Anext,Bnext = quad_rep[(quad_no+1)%self.robot_num]
            cbf_curr, lamb_curr, mu_curr = self.get_minimum_dist(
                Ai,
                Bi,
                Anext,
                Bnext
            )
            cbf_p[self.n_obs + self.n_obs*self.robot_num + quad_no] = cbf_curr
            # Initialize lambda mu and omega input values
            model_u[st_val + (len_lambda + len_lambda + 1)*quad_no:st_val + (len_lambda + len_lambda + 1)*quad_no+len_lambda]                           = lamb_curr.reshape((len_lambda,1))
            model_u[st_val + (len_lambda + len_lambda + 1)*quad_no+len_lambda:st_val + (len_lambda + len_lambda + 1)*quad_no + len_lambda + len_lambda] = mu_curr.reshape((len_lambda,1))
            model_u[st_val + (len_lambda + len_lambda + 1)*(quad_no+1)-1]                                                                               = omega_curr

        print("CBF_params: ", cbf_p)
        print("Lamda-Mu-Omg shape: ", model_u.shape)

        return np.array(cbf_p).squeeze(), model_u.squeeze()
    
    def set_state(self,state, input):
        self.state = state
        self.input = input

    #given state quaternions convert it to rotation matrix
    def get_rotation_state(self,state,isNonUnitQuaternion,isSymbolic):
        q0 = state[6]
        q1 = state[7]
        q2 = state[8]
        q3 = state[9]
        if(isNonUnitQuaternion):
            mag=1
        else:
            mag = q0**2+q1**2+q2**2+q3**2
        
        if(isSymbolic):
            Rwb = ca.SX(3,3)

        else:
            Rwb = np.zeros((3,3))

       
        Rwb[0,0] = (q0**2+q1**2-q2**2-q3**2)/mag
        Rwb[0,1] = 2*(q1*q2-q0*q3)/mag
        Rwb[0,2] = 2*(q1*q3+q0*q2)/mag

        Rwb[1,0] = 2*(q1*q2+q0*q3)/mag
        Rwb[1,1] = (q0**2+q2**2-q1**2-q3**2)/mag
        Rwb[1,2] = 2*(q2*q3-q0*q1)/mag

        Rwb[2,0] = 2*(q1*q3-q0*q2)/mag
        Rwb[2,1] = 2*(q2*q3+q0*q1)/mag
        Rwb[2,2] = (q0**2+q3**2-q1**2-q2**2)/mag
        
        return Rwb

    #define the orientation of the box encompassing cable and the quadrotor
    def get_Rotation_Of_StringBox(self,pose,isSymbolic):
        if(isSymbolic):
            Rbox = ca.SX(3,3)
        else:
            Rbox = np.zeros((3,3))
        x,y,z = pose[0],pose[1],pose[2]
        pos_mag = (x**2+y**2+z**2)**0.5
        x/=pos_mag
        y/=pos_mag
        z/=pos_mag
        #Calculate the rotation of box from the cable direction
        #the box z' direction is taken along the vector because it should be cable length
        #first choose x along 1,0,0 , find y' by -cross(z,x) and x' by cross(y,z)

        Rbox[0,0] = (z**2+y**2+1e-5)**0.5
        Rbox[0,1] = 0
        Rbox[0,2] = x
        Rbox[1,0] = -y*x/(z**2+y**2+1e-5)**0.5
        Rbox[1,1] = z/(z**2+y**2+1e-5)**0.5
        Rbox[1,2] = y
        Rbox[2,0] = -z*x/(z**2+y**2+1e-5)**0.5
        Rbox[2,1] = -y/(z**2+y**2+1e-5)**0.5
        Rbox[2,2] = z

        return Rbox

    def transtion_state(self):
        Xk = self.state
        T = np.array([[Xk[0]],[Xk[1]],[Xk[2]]])
        return T
    
    def calculateCableDir(self, state, input, is_symbolic=False):
        Rwb = None
        if is_symbolic:
            Rwb = self.get_rotation_state(state,True,True)
        else:
            Rwb = self.get_rotation_state(state,True,False)

        ################################################################## 

        force = input[0:3]
        moment = input[3:6]
        cable_dirs=[]
        
        for i in range(self.robot_num):
            cable_dir = Rwb@(self.inv_P[3*i:3*i+3,0:3] @ Rwb.T @ force + self.inv_P[3*i:3*i+3,3:6] @ moment)
            cable_dirs.append(cable_dir)
        
        #NOTE: returns cable direction in world coordinate and not pose 
        return cable_dirs

    # def calculateCableDir(self,params,state,is_symbolic=False):

    #     rho_vec_list = np.vstack([np.array([params.rhos['rho'+str(k+1)]['x'],params.rhos['rho'+str(k+1)]['y'],params.rhos['rho'+str(k+1)]['z']]) for k in range(0,self.robot_num)])
    #     # Set up the skew symmetrical matrix of the distance vector from the payload's center of mass to the attach points 
    #     rho_vec_asym_mat = np.hstack([vec2asym(np.array([params.rhos['rho'+str(k+1)]['x'],params.rhos['rho'+str(k+1)]['y'],params.rhos['rho'+str(k+1)]['z']])) for k in range(0,self.robot_num)])

    #     # Stacking identity matrix for preparing cable distribution matrix
    #     identity_stack_mat = np.hstack([np.eye(3) for k in range(0,self.robot_num)])

    #     # Set up the cable distribution matrix P
    #     P = np.vstack((identity_stack_mat,rho_vec_asym_mat))

    #     # Calculate the pseudo inverse of the P matrix
    #     pseudo_inv_P = np.matmul(P.T, LA.inv(np.matmul(P, P.T)))
    #     #print("The Pseudo inverse of P is ", pseudo_inv_P)
    #     Rwb = None

    #     if is_symbolic:
    #         Rwb = self.get_rotation_state(state,True,True)
    #     else:
    #         Rwb = self.get_rotation_state(state,True,False)

    #     ################################################################## 

    #     force = state[13:16]
    #     moment = state[16:19]
    #     cable_dirs=[]
        
    #     for i in range(self.robot_num):
    #         cable_dir = Rwb@(pseudo_inv_P[3*i:3*i+3,0:3] @ Rwb.T @ force + pseudo_inv_P[3*i:3*i+3,3:6] @ moment)
    #         cable_dirs.append(cable_dir)
        
    #     #NOTE: returns cable direction in world coordinate and not pose 
    #     return cable_dirs,np.array(rho_vec_list)
    
    def add_payload_to_obstacles_constraints(self, param, obs_geo, model_x, model_u, i, safe_dist=3):
        mat_A, vec_b = obs_geo.get_convex_rep()
        robot_G, robot_g = self.payload.get_convex_rep()
        # get current value of cbf
        # cbf_curr, lamb_curr, mu_curr = self.get_minimum_dist(
        #     mat_A,
        #     vec_b,
        #     np.dot(robot_G, self.get_rotation_state(self.state,False,False).T),
        #     np.dot(np.dot(robot_G, self.get_rotation_state(self.state,False,False).T), self.transtion_state()) + robot_g,
        # )

        #if obstacle is far away no need to apply constriant
        # if(cbf_curr>0.6):
        #     return
        
        # if(cbf_curr<0):
        #     raise("payload collided")
        
        ########----------------- CASADI IMPLEMENTATION --------------------########
        # lamb = self.opti.variable(mat_A.shape[0], N)
        # mu = self.opti.variable(robot_G.shape[0], N)
        # omega = self.opti.variable(N, 1)
        # for i in range(N):
        #     Rwb = self.get_rotation_state(self.variables["x"][:, i + 1],True,True)

        #     robot_T = self.variables["x"][0:3, i + 1]
        #     # Lagrange Multiplier Constraints
        #     self.opti.subject_to(lamb[:, i] >= 0)
        #     self.opti.subject_to(mu[:, i] >= 0)

        #     # CBF constraints for payload
        #     self.opti.subject_to(
        #         -ca.mtimes(robot_g.T, mu[:, i]) + ca.mtimes((ca.mtimes(mat_A, robot_T) - vec_b).T, lamb[:, i])
        #         >= omega[i] * param.gamma ** (i + 1) * (cbf_curr - param.margin_dist) + param.margin_dist
        #     )
        #     self.opti.subject_to(
        #         ca.mtimes(robot_G.T, mu[:, i]) + ca.mtimes(ca.mtimes(Rwb.T, mat_A.T), lamb[:, i]) == 0
        #     )
        #     temp = ca.mtimes(mat_A.T, lamb[:, i])
        #     self.opti.subject_to(ca.mtimes(temp.T, temp) <= 1)

        #     # CBF parameter's constraints`1`
        #     self.opti.subject_to(omega[i] >= 0)

        #     # warm start
        #     self.opti.set_initial(lamb[:, i], lamb_curr)
        #     self.opti.set_initial(mu[:, i], mu_curr)
        #     self.opti.set_initial(omega[i], 0.1)
        ########--------------------------------------------------------########

        # lamb = ca.SX.sym(f"lamb_pl_obs_{i}",mat_A.shape[0],1)
        # mu = ca.SX.sym(f"mu_pl_obs_{i}",robot_G.shape[0],1)
        # omega = ca.SX.sym(f"omega_pl_obs_{i}")
        len_lambda  = param["lambda"]
        len_mu      = param["mu"]
        lamb  = model_u[(len_lambda + len_mu + 1)*i:(len_lambda + len_mu + 1)*i+len_lambda]
        mu    = model_u[(len_lambda + len_mu + 1)*i+len_lambda:(len_lambda + len_mu + 1)*i + len_lambda + len_mu]
        omega = model_u[(len_lambda + len_mu + 1)*(i+1)-1]
        # ocp.add_variable()
        Rwb = self.get_rotation_state(model_x,True,True)
        robot_T = model_x[:3]
        # 1
        # self.hlist.append(lamb)
        # self.hlist_lb.append(ca.SX.zeros(mat_A.shape[0],1))
        # self.hlist_ub.append(ca.SX(10)*ca.SX.ones(mat_A.shape[0],1))
        self.hlist = ca.vertcat(self.hlist,lamb)
        # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(mat_A.shape[0],1))
        # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX(10)*ca.SX.ones(mat_A.shape[0],1))      
        self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(mat_A.shape[0])))
        self.hlist_ub = np.concatenate((self.hlist_ub, 10*np.ones(mat_A.shape[0])))

        # 2
        # self.hlist.append(mu)
        # self.hlist_lb.append(ca.SX.zeros(robot_G.shape[0],1))
        # self.hlist_ub.append(ca.SX(10)*ca.SX.ones(robot_G.shape[0],1))
        self.hlist = ca.vertcat(self.hlist,mu)
        # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(robot_G.shape[0],1))
        # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX(10)*ca.SX.ones(robot_G.shape[0],1))
        self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(robot_G.shape[0])))
        self.hlist_ub = np.concatenate((self.hlist_ub, 10*np.ones(robot_G.shape[0])))
        
        # 3
        # self.hlist.append(-ca.mtimes(robot_g.T, mu) + ca.mtimes((ca.mtimes(mat_A, robot_T) - vec_b).T, lamb)
        #         - omega * self.gamma * (cbf_curr - param["margin"]) - param["margin"])
        # self.hlist_lb.append(0)
        # self.hlist_ub.append(100)
        self.hlist = ca.vertcat(self.hlist,-ca.mtimes(robot_g.T, mu) + ca.mtimes((ca.mtimes(mat_A, robot_T) - vec_b).T, lamb)
                - omega * self.gamma * (self.cbf_p[i] - param["margin"]) - param["margin"])
        # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
        # self.hlist_ub = ca.vertcat(self.hlist_ub,100)
        self.hlist_lb = np.append(self.hlist_lb, 0)
        self.hlist_ub = np.append(self.hlist_ub, 100)  
        # 4
        # self.hlist.append(ca.mtimes(robot_G.T, mu) + ca.mtimes(ca.mtimes(Rwb.T, mat_A.T), lamb))
        # self.hlist_lb.append(0)
        # self.hlist_ub.append(0)
        self.hlist = ca.vertcat(self.hlist,ca.mtimes(robot_G.T, mu) + ca.mtimes(ca.mtimes(Rwb.T, mat_A.T), lamb))
        # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(robot_G.shape[1]))      
        # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX.zeros(robot_G.shape[1]))
        self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(robot_G.shape[1])))
        self.hlist_ub = np.concatenate((self.hlist_ub, np.zeros(robot_G.shape[1])))  
        # 5
        temp = ca.mtimes(mat_A.T, lamb)
        # self.hlist.append(ca.mtimes(temp.T, temp))
        # self.hlist_lb.append(0)
        # self.hlist_ub.append(1)
        self.hlist = ca.vertcat(self.hlist,ca.mtimes(temp.T, temp))
        # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
        # self.hlist_ub = ca.vertcat(self.hlist_ub,1)
        self.hlist_lb = np.append(self.hlist_lb, 0)
        self.hlist_ub = np.append(self.hlist_ub, 1)  
        # 6
        # self.hlist.append(omega)
        # self.hlist_lb.append(0)
        # self.hlist_ub.append(10)
        self.hlist = ca.vertcat(self.hlist,omega)
        # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
        # self.hlist_ub = ca.vertcat(self.hlist_ub,10)
        self.hlist_lb = np.append(self.hlist_lb, 0)
        self.hlist_ub = np.append(self.hlist_ub, 10) 

        # ocp.add_variable(f"lamb_pl_obs_{i}",lamb)
        # ocp.add_variable(f"mu_pl_obs_{i}",mu)
        # ocp.add_variable(f"omega_pl_obs_{i}",omega)

        # self.warm_start[f"lamb_pl_obs_{i}"] = lamb_curr
        # self.warm_start[f"mu_pl_obs_{i}"] = mu_curr
        # self.warm_start[f"omega_pl_obs_{i}"] = 0.1
    
    def add_cablesNquadrotors_to_obstacles_constraints(self, param, obs_geo, model_x, model_u, model_x_i, model_u_FMV, i,safe_dist=3):
        #NOTE: returns cable direction in world coordinate and not pose 
        # poses,rho_vec_list= self.calculateCableDir(MPC_param,self.state,False)
        # poses = self.calculateCableDir(self.state,self.input,False)
        poses = self.calculateCableDir(model_x_i,model_u_FMV,True)
        for quad_no in range(len(self.quad)):
            mat_A, vec_b = obs_geo.get_convex_rep()
            robot_G, robot_g = self.quad[quad_no].get_convex_rep()
            #print("A= ",robot_G,"B= ",robot_g)
            # Rwb = self.get_rotation_state(self.state,False,False)
            # get current value of cbf
            pose = poses[quad_no]
            x,y,z = pose[0],pose[1],pose[2]
            pos_mag = (x**2+y**2+z**2)**0.5
            x/=pos_mag
            y/=pos_mag
            z/=pos_mag

            offset = ca.SX(3,1)
            offset[0] = x/2
            offset[1] = y/2
            offset[2] = z/2
            
            # Rbox = self.get_Rotation_Of_StringBox(pose,False)

            # Tbox = np.array(self.state[0:3]).T + Rwb@(self.rho_vec_list[quad_no]).T + np.array(self.params.cable_length).T*np.array([x/2,y/2,z/2]).T

            # Tbox = Tbox.reshape(3,1)
            # cbf_curr, lamb_curr, mu_curr = self.get_minimum_dist(
            #     mat_A,
            #     vec_b,
            #     np.dot(robot_G, Rbox.T),
            #     np.dot(np.dot(robot_G, Rbox.T), Tbox) + robot_g,
            # )
           
            # if(cbf_curr>0.6):
            #     continue
            
            # if(cbf_curr<0):
            #     print(f'cbf_curr = {cbf_curr}')
            #     raise Exception("cables collided")
            
        ########----------------- CASADI IMPLEMENTATION --------------------########
            # lamb = self.opti.variable(mat_A.shape[0], param.horizon_dcbf)
            # mu = self.opti.variable(robot_G.shape[0], param.horizon_dcbf)
            # omega = self.opti.variable(param.horizon, 1)
            # for i in range(param.horizon_dcbf):
            #     x,y,z = pose[0],pose[1],pose[2]
            #     pos_mag = (x**2+y**2+z**2+1e-5)**0.5
            #     x/=pos_mag
            #     y/=pos_mag
            #     z/=pos_mag

                # Rbox = self.get_Rotation_Of_StringBox(pose,True)
                # Rwb = self.get_rotation_state(self.variables["x"][:, i + 1],True,True)

            
                # offset = ca.MX(3,1)
                # offset[0] = x/2
                # offset[1] = y/2
                # offset[2] = z/2

                # robot_T = self.variables["x"][0:3, i + 1]
                # robot_T =(self.variables["x"][0:3, i + 1]) + Rwb@(self.rho_vec_list[quad_no]).T + np.array(self.params.cable_length_list).T*offset
                #print(robot_T.shape) 
                # self.opti.subject_to(lamb[:, i] >= 0)
                # self.opti.subject_to(mu[:, i] >= 0)
                # self.opti.subject_to(
                #     -ca.mtimes(robot_g.T, mu[:, i]) + ca.mtimes((ca.mtimes(mat_A, robot_T) - vec_b).T, lamb[:, i])
                #     >= omega[i] * param.gamma ** (i + 1) * (cbf_curr - param.margin_dist) + param.margin_dist
                # )
                # self.opti.subject_to(
                #     ca.mtimes(robot_G.T, mu[:, i]) + ca.mtimes(ca.mtimes(Rbox.T, mat_A.T), lamb[:, i]) == 0
                # )
                # temp = ca.mtimes(mat_A.T, lamb[:, i])
                # self.opti.subject_to(ca.mtimes(temp.T, temp) <= 1)
                # self.opti.subject_to(omega[i] >= 0)
                
                # self.opti.set_initial(lamb[:, i], lamb_curr)
                # self.opti.set_initial(mu[:, i], mu_curr)
                # self.opti.set_initial(omega[i], 0.1)
        ########--------------------------------------------------------########
            # duality-cbf constraints
            # lamb = ca.SX.sym(f"lamb_cable_obs_{quad_no}{i}",mat_A.shape[0],1)
            # mu = ca.SX.sym(f"mu_cable_obs_{quad_no}{i}",robot_G.shape[0],1)
            # omega = ca.SX.sym(f"omega_cable_obs_{quad_no}{i}")
            len_lambda  = param["lambda"]
            len_mu      = param["mu"]
            st_val = (len_lambda + len_mu + 1)*self.n_obs + i*self.robot_num*(len_lambda + len_lambda + 1)
            lamb   = model_u[st_val + (len_lambda + len_lambda + 1)*quad_no:st_val + (len_lambda + len_lambda + 1)*quad_no+len_lambda]
            mu     = model_u[st_val + (len_lambda + len_lambda + 1)*quad_no+len_lambda:st_val + (len_lambda + len_lambda + 1)*quad_no + len_lambda + len_lambda]
            omega  = model_u[st_val + (len_lambda + len_lambda + 1)*(quad_no+1)-1]
            # ocp.add_variable()
            # Rbox = self.get_Rotation_Of_StringBox(pose,True)
            Rwb = self.get_rotation_state(model_x,True,True)

            robot_T =model_x[:3] + Rwb@(self.rho_vec_list[quad_no]).T + np.array(self.params.cable_length).T*offset
            # 1
            # self.hlist.append(lamb)
            # self.hlist_lb.append(ca.SX.zeros(mat_A.shape[0],1))
            # self.hlist_ub.append(ca.SX(10)*ca.SX.ones(mat_A.shape[0],1))
            self.hlist = ca.vertcat(self.hlist,lamb)
            # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(mat_A.shape[0],1))      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX(10)*ca.SX.ones(mat_A.shape[0],1))
            self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(mat_A.shape[0])))
            self.hlist_ub = np.concatenate((self.hlist_ub, 10*np.ones(mat_A.shape[0])))
            # 2
            # self.hlist.append(mu)
            # self.hlist_lb.append(ca.SX.zeros(robot_G.shape[0],1))
            # self.hlist_ub.append(ca.SX(10)*ca.SX.ones(robot_G.shape[0],1))
            self.hlist = ca.vertcat(self.hlist,mu)
            # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(robot_G.shape[0],1))      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX(10)*ca.SX.ones(robot_G.shape[0],1))  
            self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(robot_G.shape[0])))
            self.hlist_ub = np.concatenate((self.hlist_ub, 10*np.ones(robot_G.shape[0])))
            # 3
            # self.hlist.append(-ca.mtimes(robot_g.T, mu) + ca.mtimes((ca.mtimes(mat_A, robot_T) - vec_b).T, lamb)
            #         - omega * self.gamma * (cbf_curr - param["margin"]) - param["margin"])
            # self.hlist_lb.append(0)
            # self.hlist_ub.append(100)
            self.hlist = ca.vertcat(self.hlist,-ca.mtimes(robot_g.T, mu) + ca.mtimes((ca.mtimes(mat_A, robot_T) - vec_b).T, lamb)
                    - omega * self.gamma * (self.cbf_p[self.n_obs + i*self.robot_num + quad_no] - param["margin"]) - param["margin"])
            # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,100)
            self.hlist_lb = np.append(self.hlist_lb, 0)
            self.hlist_ub = np.append(self.hlist_ub, 100) 
            # 4
            # self.hlist.append(ca.mtimes(robot_G.T, mu) + ca.mtimes(ca.mtimes(Rwb.T, mat_A.T), lamb))
            # self.hlist_lb.append(ca.SX.zeros(robot_G.shape[1]))
            # self.hlist_ub.append(ca.SX.zeros(robot_G.shape[1]))
            self.hlist = ca.vertcat(self.hlist,ca.mtimes(robot_G.T, mu) + ca.mtimes(ca.mtimes(Rwb.T, mat_A.T), lamb))
            # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(robot_G.shape[1]))      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX.zeros(robot_G.shape[1]))
            self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(robot_G.shape[1])))
            self.hlist_ub = np.concatenate((self.hlist_ub, np.zeros(robot_G.shape[1])))
            # 5
            temp = ca.mtimes(mat_A.T, lamb)
            # self.hlist.append(ca.mtimes(temp.T, temp))
            # self.hlist_lb.append(0)
            # self.hlist_ub.append(1)
            self.hlist = ca.vertcat(self.hlist,ca.mtimes(temp.T, temp))
            # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,1)
            self.hlist_lb = np.append(self.hlist_lb, 0)
            self.hlist_ub = np.append(self.hlist_ub, 1) 
            # 6
            # self.hlist.append(omega)
            # self.hlist_lb.append(0)
            # self.hlist_ub.append(10)
            self.hlist = ca.vertcat(self.hlist,omega)
            # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,10)
            self.hlist_lb = np.append(self.hlist_lb, 0)
            self.hlist_ub = np.append(self.hlist_ub, 10) 

            # ocp.add_variable(f"lamb_cable_obs_{quad_no}{i}",lamb)
            # ocp.add_variable(f"mu_cable_obs_{quad_no}{i}",mu)
            # ocp.add_variable(f"omega_cable_obs_{quad_no}{i}",omega)

            # self.warm_start[f"lamb_cable_obs_{quad_no}{i}"] = lamb_curr
            # self.warm_start[f"mu_cable_obs_{quad_no}{i}"] = mu_curr
            # self.warm_start[f"omega_cable_obs_{quad_no}{i}"] = 0.1
        
    
    def getQuadRepresentation(self,poses,rho_vec_list,quad_no,is_symbolic):
        pose = poses[quad_no]
        robot_G, robot_g = self.quad[quad_no].get_convex_rep()
        Rwb = self.get_rotation_state(self.state,False,False)
        if(is_symbolic):
            Rbox = ca.SX(3,3)
            Rbox = self.get_Rotation_Of_StringBox(pose,True)
        else:
            Rbox = np.eye(3)
            Rbox = self.get_Rotation_Of_StringBox(pose,False)
        x,y,z = pose[0],pose[1],pose[2]
        pos_mag = (x**2+y**2+z**2)**0.5
        x/=pos_mag
        y/=pos_mag
        z/=pos_mag
        # #Calculate the rotation of box from the cable direction
        # #the box z' direction is taken along the vector because it should be cable length
        # #first choose x along 1,0,0 , find y' by -cross(z,x) and x' by cross(y,z)

        
        if(is_symbolic):
            Tbox = ca.SX(3,1)
            Tbox[0] = x/2
            Tbox[1] = y/2
            Tbox[2] = z/2
            position = ca.SX(3,1)
            position[0] = self.state[0]
            position[1] = self.state[1]
            position[2] = self.state[2]

            Tbox = position + Rwb@(rho_vec_list[quad_no]).T + np.array(self.params.cable_length).T*Tbox
        else:
            Tbox = np.array(self.state[0:3]).T + Rwb@(rho_vec_list[quad_no]).T + np.array(self.params.cable_length).T*np.array([x/2,y/2,z/2]).T
            Tbox = Tbox.reshape(3,1)

        A  = robot_G @ Rbox.T
        B = ((robot_G@ Rbox.T)@ Tbox) + robot_g

        return (A,B)
    
    def add_quad_to_quad_const(self, param, model_u, model_x_i, model_u_FMV, safe_dist=3):
        #NOTE: returns cable direction in world coordinate and not pose 
        # poses= self.calculateCableDir(self.state,self.input,False)
        poses= self.calculateCableDir(model_x_i,model_u_FMV,True)
        quad_rep = []
        for quad_no in range(len(self.quad)):
            # quad_rep.append(self.getQuadRepresentation(poses,self.rho_vec_list,quad_no,False))
            quad_rep.append(self.getQuadRepresentation(poses,self.rho_vec_list,quad_no,True))
        
        
        for quad_no in range(len(self.quad)):
            Ai,Bi =  quad_rep[quad_no]
            Anext,Bnext = quad_rep[(quad_no+1)%self.robot_num]
            # cbf_curr, lamb_curr, mu_curr = self.get_minimum_dist(
            #     Ai,
            #     Bi,
            #     Anext,
            #     Bnext
            # )
           
            # if(cbf_curr>0.2):
            #     continue
            
            # if(cbf_curr<0):
            #     raise Exception("quads collided")

            ########----------------- CASADI IMPLEMENTATION --------------------########
            # lamb = self.opti.variable(Ai.shape[0], param.horizon_dcbf)
            # mu = self.opti.variable(Anext.shape[0], param.horizon_dcbf)
            # omega = self.opti.variable(param.horizon, 1)
            # for i in range(param.horizon_dcbf):
            #     pose_sym,rho_vec_list= self.calculateCableDir(MPC_param,self.variables["x"][:,i+1],True)
            #     quad_rep = []
            #     for quad_no in range(len(self.quad)):
            #         quad_rep.append(self.getQuadRepresentation(poses,rho_vec_list,quad_no,True))
                
            #     self.opti.subject_to(lamb[:, i] >= 0)
            #     self.opti.subject_to(mu[:, i] >= 0)
            #     self.opti.subject_to(
            #         -ca.mtimes(Bnext.T, mu[:, i]) + ca.mtimes((Ai - Bi).T, lamb[:, i])
            #         >= omega[i] * param.gamma ** (i + 1) * (cbf_curr - param.margin_dist) + param.margin_dist
            #     )
            #     self.opti.subject_to(
            #         ca.mtimes(Anext.T, mu[:, i]) + ca.mtimes( Ai.T, lamb[:, i]) == 0
            #     )
            #     temp = ca.mtimes(Ai.T, lamb[:, i])
            #     self.opti.subject_to(ca.mtimes(temp.T, temp) <= 1)
            #     self.opti.subject_to(omega[i] >= 0)
            #     # warm start
            #     self.opti.set_initial(lamb[:, i], lamb_curr)
            #     self.opti.set_initial(mu[:, i], mu_curr)
            #     self.opti.set_initial(omega[i], 0.1)
            ########--------------------------------------------------------########        
            # lamb = ca.SX.sym(f"lamb_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}",Ai.shape[0],1)
            # mu = ca.SX.sym(f"mu_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}",Anext.shape[0],1)
            # omega = ca.SX.sym(f"omega_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}")
            len_lambda  = param["lambda"]
            len_mu      = param["mu"]
            st_val = (len_lambda + len_mu + 1)*self.n_obs + self.n_obs*self.robot_num*(len_lambda + len_lambda + 1)
            lamb   = model_u[st_val + (len_lambda + len_lambda + 1)*quad_no:st_val + (len_lambda + len_lambda + 1)*quad_no+len_lambda]
            mu     = model_u[st_val + (len_lambda + len_lambda + 1)*quad_no+len_lambda:st_val + (len_lambda + len_lambda + 1)*quad_no + len_lambda + len_lambda]
            omega  = model_u[st_val + (len_lambda + len_lambda + 1)*(quad_no+1)-1]
            # ocp.add_variable()
            # quad_rep = []
            # for quad_no in range(len(self.quad)):
            #     quad_rep.append(self.getQuadRepresentation(poses,self.rho_vec_list,quad_no,True))
            # 1
            # self.hlist.append(lamb)
            # self.hlist_lb.append(ca.SX.zeros(Ai.shape[0],1))
            # self.hlist_ub.append(ca.SX(10)*ca.SX.ones(Ai.shape[0],1))
            self.hlist = ca.vertcat(self.hlist,lamb)
            # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(Ai.shape[0],1))      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX(10)*ca.SX.ones(Ai.shape[0],1))
            self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(Ai.shape[0])))
            self.hlist_ub = np.concatenate((self.hlist_ub, 10*np.ones(Ai.shape[0])))
            # 2
            # self.hlist.append(mu)
            # self.hlist_lb.append(ca.SX.zeros(Anext.shape[0],1))
            # self.hlist_ub.append(ca.SX(10)*ca.SX.ones(Anext.shape[0],1))
            self.hlist = ca.vertcat(self.hlist,mu)
            # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(Anext.shape[0],1))      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX(10)*ca.SX.ones(Anext.shape[0],1)) 
            self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(Anext.shape[0])))
            self.hlist_ub = np.concatenate((self.hlist_ub, 10*np.ones(Anext.shape[0])))
            # 3
            # self.hlist.append(-ca.mtimes(Bnext.T, mu) + ca.mtimes((Ai - Bi).T, lamb)
            #         - omega * self.gamma * (cbf_curr - param["margin"]) - param["margin"])
            # self.hlist_lb.append(0)
            # self.hlist_ub.append(100)
            # self.hlist = ca.vertcat(self.hlist,-ca.mtimes(Bnext.T, mu) + ca.mtimes((Ai - Bi).T, lamb)
            #         - omega * self.gamma * (self.cbf_p[self.n_obs + self.n_obs*self.robot_num + quad_no] - param["margin"]) + param["margin"])
            self.hlist = ca.vertcat(self.hlist,-ca.mtimes(Bnext.T, mu) + ca.mtimes(-Bi.T, lamb)
                    - omega * self.gamma * (self.cbf_p[self.n_obs + self.n_obs*self.robot_num + quad_no] - param["margin"]) + param["margin"])
            # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,100)
            self.hlist_lb = np.append(self.hlist_lb, 0)
            self.hlist_ub = np.append(self.hlist_ub, 100)
            # 4
            # self.hlist.append(ca.mtimes(Anext.T, mu) + ca.mtimes(Ai.T, lamb))
            # self.hlist_lb.append(ca.SX.zeros(Anext.shape[1]))
            # self.hlist_ub.append(ca.SX.zeros(Anext.shape[1]))
            self.hlist = ca.vertcat(self.hlist,ca.mtimes(Anext.T, mu) + ca.mtimes(Ai.T, lamb))  
            # self.hlist_lb = ca.vertcat(self.hlist_lb,ca.SX.zeros(Anext.shape[1]))      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,ca.SX.zeros(Anext.shape[1]))
            self.hlist_lb = np.concatenate((self.hlist_lb, np.zeros(Anext.shape[1])))
            self.hlist_ub = np.concatenate((self.hlist_ub, np.zeros(Anext.shape[1])))
            # 5
            temp = ca.mtimes(Ai.T, lamb)
            # self.hlist.append(ca.mtimes(temp.T, temp))
            # self.hlist_lb.append(0)
            # self.hlist_ub.append(1)
            self.hlist = ca.vertcat(self.hlist,ca.mtimes(temp.T, temp))
            # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,1)
            self.hlist_lb = np.append(self.hlist_lb, 0)
            self.hlist_ub = np.append(self.hlist_ub, 1)
            # 6
            # self.hlist.append(omega)
            # self.hlist_lb.append(0)
            # self.hlist_ub.append(10)
            self.hlist = ca.vertcat(self.hlist,omega)
            # self.hlist_lb = ca.vertcat(self.hlist_lb,0)      
            # self.hlist_ub = ca.vertcat(self.hlist_ub,10)
            self.hlist_lb = np.append(self.hlist_lb, 0)
            self.hlist_ub = np.append(self.hlist_ub, 10)

            # ocp.add_variable(f"lamb_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}",lamb)
            # ocp.add_variable(f"mu_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}",mu)
            # ocp.add_variable(f"omega_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}",omega)

            # self.warm_start[f"lamb_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}"] = lamb_curr
            # self.warm_start[f"mu_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}"] = mu_curr
            # self.warm_start[f"omega_quad_quad_{quad_no}{(quad_no+1)%self.robot_num}"] = 0.1
            
    #param is a class {horizon:int,}
    def setup(self,cbf_param,init_state, init_input, model_x, model_u):
        self.set_state(init_state, init_input)
        model_x_next = self.dynamics_opt(model_x,model_u)
        #add wall const
        for i,obs in enumerate(self.obstacles):
            self.add_payload_to_obstacles_constraints(cbf_param,obs, model_x_next, model_u[9:], i)
            self.add_cablesNquadrotors_to_obstacles_constraints(cbf_param, obs, model_x_next, model_u[9:], model_x, model_u[:9], i)
       
        self.add_quad_to_quad_const(cbf_param, model_u[9:], model_x, model_u[:9])
        return self.hlist, self.hlist_lb, self.hlist_ub



        

def main():
    # Load all the file paths
    nmpc_filename = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/payload_nmpc_params.yaml"
    payload_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/load_params/triangular_payload.yaml"
    uav_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/uav_params/"
    mechanism_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/attach_mechanism/cable/3_robots_triangular_payload_0-5m.yaml"
    payload_control_gain_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_cable_gains.yaml"
    uav_control_gain_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/"
    obstacles_path =  "/home/dhruv/RotorTM/src/rotor_tm_config/config/obstacles/obstacles.yaml"
    cbf_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/cbf_params/params.yaml"
    # Store the obstacles in a list
    with open(obstacles_path, 'r') as file:
        obstacle_params = yaml.safe_load(file)
    with open(cbf_params_path, 'r') as file:
        cbf_params = yaml.safe_load(file)
    # Read the parameters using your read_params module
    read_params_funcs = read_params.read_params()
    payload_params, quad_params = read_params_funcs.system_setup(payload_params_path, uav_params_path, mechanism_params_path, payload_control_gain_path, uav_control_gain_path)
    control_params = read_params_funcs.read_pl_nmpc_params(nmpc_filename)
    # Get the rho, cable params, mass and gravity params
    rho_vec_list = payload_params.rho_vec_list
    cabel_length = payload_params.cable_length
    mass = payload_params.mass
    gravity = payload_params.grav
    # Initialize the hover condition
    hover_condition = np.array([0, 0, mass*gravity, 0, 0, 0])
    # Get the current input
    current_force = hover_condition[:3]
    #Instantiate the Optimization class
    opimization = CBFDualityOptimization(payload_params,obstacle_params["obstacles"])
    print('Hi from cbf_constraints.')


if __name__ == '__main__':
    main()

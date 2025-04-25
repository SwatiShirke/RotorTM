
import time, os
import numpy as np
from testing_pl_payload_controller import *
from plotFcn import *
from tracks.readDataFcn import read_interpl, visualize_traj
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d
import ipdb
from utils import read_yaml, QuatToRot
from rotor_tm_utils import read_params
import rclpy
from rclpy.clock import Clock
from rclpy.time import Time
import yaml

def terminate_sim(simX,last_pose, threshold):
    dist = np.linalg.norm(simX[0:3] - last_pose )
    val = True if (dist <= threshold) else False   
    return val 


if __name__ == '__main__':
    nmpc_filename = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/payload_nmpc_params.yaml"
    #pl_filename = '/home/dhruv/RotorTM/src/rotor_tm_config/config/load_params/triangular_payload.yaml' 

    #**Case 1
    payload_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/load_params/triangular_payload.yaml"
    uav_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/uav_params/"
    mechanism_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/attach_mechanism/cable/3_robots_triangular_payload_0-5m.yaml"
    payload_control_gain_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_cable_gains.yaml"
    uav_control_gain_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/"
    obstacles_path =  "/home/dhruv/RotorTM/src/rotor_tm_config/config/obstacles/obstacles.yaml"
    cbf_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/cbf_params/params.yaml"

    with open(obstacles_path, 'r') as file:
        obstacle_params = yaml.safe_load(file)
    with open(cbf_params_path, 'r') as file:
        cbf_params = yaml.safe_load(file)

    read_params_funcs = read_params.read_params()
    payload_params, quad_params = read_params_funcs.system_setup(payload_params_path,uav_params_path,mechanism_params_path, payload_control_gain_path, uav_control_gain_path)
    control_params = read_params_funcs.read_pl_nmpc_params(nmpc_filename)
     
    #read and track and interpolate
    track = 'tracks/trajectory.txt'
    [time_points, pos_ref, vel_ref, acc_ref, yaw_ref, yawr_ref, start_pose, last_pose ] = read_interpl(track)
    #visualize_traj(track)
    Tf = 0.1    # time step
    N = 10     # prediction horizon
    T = 10  # maximum simulation time[s]
    sref_N = 2  # reference for final reference progress
    Ts = Tf / N 
    Nsim = int(T /Ts)

    err_theshold = 1
    
    #mg = model.mass * model.g
    mg = payload_params.mass * payload_params.grav
    u_ref = np.array([0,0,mg, 0,0,0, 0,0,0]) 

    init_state = [start_pose[0],start_pose[1],start_pose[2], 0,0,0, 1,0,0,0, 0,0,0]
    sttttt_timeeee = time.time()
    model, acados_solver, acados_integrator, cbf_constraints, h_fun = controller_setup(control_params, payload_params, obstacle_params, cbf_params, np.array(init_state), u_ref) 
    # model, acados_solver, acados_integrator, cbf_constraints = controller_setup(control_params, payload_params, obstacle_params, cbf_params, np.array(init_state), u_ref) 
    print(time.time()-sttttt_timeeee)
    # ipdb.set_trace()
    nx = model.x.rows()
    nu = model.u.rows()
    ny = nx + nu
    
    simX = np.zeros((Nsim+1, nx), dtype= float)
    simU = np.zeros((Nsim+1, nu), dtype= float)
    model.x0 = init_state
    simX[0,:] = model.x0 
    
    #simulation loop 
    t0 = 0 
    rclpy.init()
    
    clock = Clock()

    # Get the current time
    start_time = clock.now()
    
    C1_list = np.zeros((6,10))
    C2_list = np.zeros((5,10))
    C3_list = np.zeros((1,10))
    C4_list = np.zeros((3,10))
    C5_list = np.zeros((1,10))

    for i in range(10):
        # Get the state and the next state
        t_j  = i*Ts
        t_j2 = (i+1)*Ts
        
        x_ref_j  = pos_ref[0](t_j)
        y_ref_j  = pos_ref[1](t_j)
        z_ref_j  = pos_ref[2](t_j)
        vx_ref_j = vel_ref[0](t_j)
        vy_ref_j = vel_ref[1](t_j)
        vz_ref_j = vel_ref[2](t_j)

        x_ref_j2  = pos_ref[0](t_j2)
        y_ref_j2  = pos_ref[1](t_j2)
        z_ref_j2  = pos_ref[2](t_j2)
        vx_ref_j2 = vel_ref[0](t_j2)
        vy_ref_j2 = vel_ref[1](t_j2)
        vz_ref_j2 = vel_ref[2](t_j2)
        
        x_j  = np.array([x_ref_j, y_ref_j, z_ref_j, vx_ref_j, vy_ref_j, vz_ref_j, 1, 0, 0, 0, 0, 0, 0])
        x_j2 = np.array([x_ref_j2, y_ref_j2, z_ref_j2, vx_ref_j2, vy_ref_j2, vz_ref_j2, 1, 0, 0, 0, 0, 0, 0])

        robot_T = x_j2[:3]
        Rwb     = cbf_constraints.get_rotation_state(x_j2,False,False)
        
        # Calculate the min distance and the lambda and mu values
        cbf_p, model_lamb_mu_omg = cbf_constraints.get_all_minimum_dist(cbf_params)
        
        ############################################################################################################################
        # print("------------- PAYLOAD OBSTACLE -----------")
        # lamb = model_lamb_mu_omg[:6]
        # mu   = model_lamb_mu_omg[6:11]
        # # Get the payload and obstacle polytopes
        # mat_A, vec_b     = cbf_constraints.obstacles[0].get_convex_rep()
        # robot_G, robot_g = cbf_constraints.payload.get_convex_rep()

        # # constraint 1:
        # c1 = lamb
        # print("C1: ")
        # print(c1)
        # C1_list[:,i] = c1

        # # constraint 2:
        # c2 = mu
        # print("C2: ")
        # print(c2)
        # C2_list[:,i] = c2

        # # constraint 3:
        # print("Robot_T shape")
        # print(robot_T)
        # print("Vec_b shape")
        # print(vec_b.shape)
        # print("Val 1: ", -robot_g.T@ mu)
        # print("Val 2: ", (mat_A @ robot_T.reshape(3,1) - vec_b).T @ lamb)
        # print("Val 3: ", -cbf_params["cbf_gamma"]**i * (cbf_p[0] - cbf_params["margin"]))
        # print("Val 4: ", cbf_params["margin"])
        # c3 = -robot_g.T@ mu + (mat_A @ robot_T.reshape(3,1) - vec_b).T @ lamb - cbf_params["cbf_gamma"]**(i+1) * (cbf_p[0] - cbf_params["margin"]) + cbf_params["margin"]
        # print("C3: ")
        # print(c3)
        # C3_list[0,i] = c3[0]

        # # constraint 4:
        # c4 = np.dot(robot_G.T, mu) + np.dot(np.dot(Rwb.T, mat_A.T), lamb)
        # print("C4: ")
        # print(c4)
        # C4_list[:,i] = c4
        
        # # constraint 5:
        # temp = np.dot(mat_A.T, lamb)
        # c5 = np.dot(temp.T, temp)
        # temp = ca.mtimes(mat_A.T, lamb)
        # print("C5: ")
        # print(c5)
        # C5_list[:,i] = c5

        # constraint 6:
        # print(omega)

        ############################################################################################################################
        print("------------- QUADROTOR OBSTACLE -----------")
        # A = np.array([[0,0,1],
        #               [0,0,-1],
        #               [1,0,0],
        #               [1,0,0],
        #               [0,1,0],
        #               [0,-1,0]])
        # b = np.array([[2],
        #               [0],
        #               [3],
        #               [2.5],
        #               [1.767],
        #               [-1.267]])
        # G = np.array([[0,0,1],
        #               [0,0,-1],
        #               [1,0,0],
        #               [1,0,0],
        #               [0,1,0],
        #               [0,-1,0]])
        # g = np.array([[0.5],
        #               [-0.01125],
        #               [-0.08],
        #               [0.23],
        #               [-0.19],
        #               [0.342]])
        # opt,lamb,mu = cbf_constraints.get_minimum_dist(A,b,G,g)
        # print("OPT: ", opt)
        # print("LAAAMBBBB: ", lamb)
        # print("MMUUUUUUU: ", mu)

        poses = cbf_constraints.calculateCableDir(x_j,u_ref,False)
        for j in range(3):
            lamb = model_lamb_mu_omg[12+13*j:18+13*j]
            mu   = model_lamb_mu_omg[18+13*j:24+13*j]
            # Get the payload and obstacle polytopes
            mat_A, vec_b     = cbf_constraints.obstacles[0].get_convex_rep()
            robot_G, robot_g = cbf_constraints.quad[j].get_convex_rep()

            pose = poses[j]
            x,y,z = pose[0],pose[1],pose[2]

            pos_mag = (x**2+y**2+z**2)**0.5
            if pos_mag > 0:
                x/=pos_mag
                y/=pos_mag
                z/=pos_mag

            offset = np.zeros((3,1))
            offset[0] = x/2
            offset[1] = y/2
            offset[2] = z/2

            robot_T =x_j2[:3].reshape(3,1) + Rwb@(cbf_constraints.rho_vec_list[j]).reshape(3,1) + np.array(cbf_constraints.params.cable_length[0])*offset

            # constraint 1:
            c1 = lamb
            print("C1: ")
            print(c1)
            # C1_list[:,i] = c1

            # constraint 2:
            c2 = mu
            print("C2: ")
            print(c2)
            # C2_list[:,i] = c2

            # constraint 3:
            print("Robot_T shape")
            print(robot_T)

            print("Val 1: ", -robot_g.T@ mu)
            print("Val 2: ", (mat_A @ robot_T.reshape(3,1) - vec_b).T @ lamb)
            print("Val 3: ", -cbf_params["cbf_gamma"]**i * (cbf_p[j] - cbf_params["margin"]))
            print("Val 4: ", cbf_params["margin"])
            print("Mat_A: ",mat_A)
            print("Robot_T: ", robot_T)
            print("Vec_b: ", vec_b)
            print("lamb: ", lamb)
            c3 = -robot_g.T@ mu + (mat_A @ robot_T.reshape(3,1) - vec_b).T @ lamb - cbf_params["cbf_gamma"]**i * (cbf_p[j] - cbf_params["margin"]) + cbf_params["margin"]
            print("C3: ")
            print(c3)
            # C3_list[0,i] = c3[0]

            # constraint 4:
            c4 = np.dot(robot_G.T, mu) + np.dot(np.dot(Rwb.T, mat_A.T), lamb)
            print("C4: ")
            print(c4)
            # C4_list[:,i] = c4
            
            # constraint 5:
            temp = np.dot(mat_A.T, lamb)
            c5 = np.dot(temp.T, temp)
            print("C5: ")
            print(c5)
            # C5_list[:,i] = c5

            # constraint 6:
            # print(omega)
        print("---------------------------------------------------")

    
    # i = np.linspace(1,10,10)
    
    # print(C1_list)
    # print(C2_list)
    # # C1
    # plt.figure()
    # labels = [f"C1_{i}" for i in range(C1_list.shape[0])]
    # plt.plot(i,C1_list[0,:])
    # plt.plot(i,C1_list[1,:])
    # plt.plot(i,C1_list[2,:])
    # plt.plot(i,C1_list[3,:])
    # plt.plot(i,C1_list[4,:])
    # plt.plot(i,C1_list[5,:])
    # plt.axhline(y=0, color='black', linestyle='--', linewidth=1)
    # plt.title("C1 constraints")
    # plt.xlabel("Steps")
    # plt.legend(labels)
    # plt.grid(True)

    # # C2
    # plt.figure()
    # labels = [f"C2_{i}" for i in range(C2_list.shape[0])]
    # plt.plot(i,C2_list[0,:])
    # plt.plot(i,C2_list[1,:])
    # plt.plot(i,C2_list[2,:])
    # plt.plot(i,C2_list[3,:])
    # plt.plot(i,C2_list[4,:])
    # plt.axhline(y=0, color='black', linestyle='--', linewidth=1)
    # plt.title("C2 constraints")
    # plt.xlabel("Steps")
    # plt.legend(labels)
    # plt.grid(True)

    # # C3
    # plt.figure()
    # labels = [f"C3_{i}" for i in range(C3_list.shape[0])]
    # plt.plot(i,C3_list[0,:])
    # plt.axhline(y=0, color='black', linestyle='--', linewidth=1)
    # plt.title("C3 constraints")
    # plt.xlabel("Steps")
    # plt.legend(labels)
    # plt.grid(True)

    # # C3
    # plt.figure()
    # labels = [f"C4_{i}" for i in range(C4_list.shape[0])]
    # plt.plot(i,C4_list[0,:])
    # plt.plot(i,C4_list[1,:])
    # plt.plot(i,C4_list[2,:])
    # plt.axhline(y=0, color='black', linestyle='--', linewidth=1)
    # plt.title("C4 constraints")
    # plt.xlabel("Steps")
    # plt.legend(labels)
    # plt.grid(True)

    # # C5
    # plt.figure()
    # labels = [f"C5_{i}" for i in range(C5_list.shape[0])]
    # plt.plot(i,C5_list[0,:])
    # plt.axhline(y=0, color='black', linestyle='--', linewidth=1)
    # plt.title("C5 constraints")
    # plt.xlabel("Steps")
    # plt.legend(labels)
    # plt.grid(True)

    # plt.show()
    

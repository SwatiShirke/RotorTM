
import time, os
import numpy as np
from payload_controller import *
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
from scipy.linalg import null_space

def terminate_sim(simX,last_pose, threshold):
    dist = np.linalg.norm(simX[0:3] - last_pose )
    val = True if (dist <= threshold) else False   
    return val 


if __name__ == '__main__':
    nmpc_filename = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/payload_nmpc_params.yaml"
    #pl_filename = '/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/load_params/triangular_payload.yaml' 

    #**Case 1
    payload_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/load_params/triangular_payload.yaml"
    uav_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/uav_params/"
    mechanism_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/attach_mechanism/cable/3_robots_triangular_payload_0-5m.yaml"
    payload_control_gain_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_cable_gains.yaml"
    uav_control_gain_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/"

    read_params_funcs = read_params.read_params()
    payload_params, quad_params = read_params_funcs.system_setup(payload_params_path,uav_params_path,mechanism_params_path, payload_control_gain_path, uav_control_gain_path)
    control_params = read_params_funcs.read_pl_nmpc_params(nmpc_filename)
    
    model, acados_solver, acados_integrator,h_list_f = controller_setup(control_params, payload_params) 

    #read and track and interpolate
    track = 'tracks/trajectory.txt'
    [time_points, pos_ref, vel_ref, acc_ref, yaw_ref, yawr_ref, start_pose, last_pose ] = read_interpl(track)
    #visualize_traj(track)
    Tf = 0.1    # time step # CHECK THE PARAMS FILE changed to 0.1
    N = 10     # prediction horizon
    T = 7  # maximum simulation time[s]
    sref_N = 2  # reference for final reference progress
    Ts = Tf / N 
    Nsim = int(T /Ts)

    ########################################
    dense_time_pt = np.linspace(time_points[0], time_points[-1], Nsim)
    pos_ref_x = pos_ref[0]
    pos_ref_y = pos_ref[1]
    pos_ref_z = pos_ref[2]
    vel_ref_x = vel_ref[0]
    vel_ref_y = vel_ref[1]
    vel_ref_z = vel_ref[2]
    ########################################

    err_theshold = 0.01 # changed 0.05 to 0.5
    nx = model.x.rows()
    nu = model.u.rows()
    ny = nx + nu
    
    simX = np.zeros((Nsim+1, nx), dtype= float)
    simU = np.zeros((Nsim+1, nu), dtype= float)
    model.x0 = [1, 1, 1, 0,0,0, 1,0,0,0, 0,0,0]  # [start_pose[0],start_pose[1],start_pose[2], 0,0,0, 1,0,0,0, 0,0,0]# changed qw to 1
    simX[0,:] = model.x0
    mg = payload_params.mass * payload_params.grav
    # mg = 0.250*9.81
    u_ref = np.array([0,0,mg, 0,0,0, 0,0,0])
    
    #simulation loop 
    t0 = 0 
    rclpy.init()
    
    clock = Clock()

    # Get the current time
    start_time = clock.now()
    # Reset Solver
    acados_solver.reset()

    for stage in range(N + 1):
        acados_solver.set(stage, "x", simX[0,:])
    for stage in range(N):
        acados_solver.set(stage, "u", u_ref)

    for i in range(Nsim - N):
        for j in range(N):
            t_j = t0 + (j) * Ts
            # print("t_j")
            # print(t_j)
            # x_ref_j = pos_ref[0](t_j)
            # y_ref_j = pos_ref[1](t_j)
            # z_ref_j = pos_ref[2](t_j)

            # vx_ref_j = vel_ref[0](t_j)
            # vy_ref_j = vel_ref[1](t_j)
            # vz_ref_j = vel_ref[2](t_j)
            
            # yaw_ref_i = yaw_ref(t_j)
            # yawr_ref_i = yawr_ref(t_j)

            # yref = np.array([x_ref_j, y_ref_j, z_ref_j,  vx_ref_j, vy_ref_j, vz_ref_j,  1,0,0,0,  0,0,yawr_ref_i, 0, 0, mg, 0, 0, 0, 0, 0, 0])# changed qw to 1

            ###########################
            x_ref_j  = pos_ref_x(dense_time_pt[i+j])
            y_ref_j  = pos_ref_y(dense_time_pt[i+j])
            z_ref_j  = pos_ref_z(dense_time_pt[i+j])
            vx_ref_j = vel_ref_x(dense_time_pt[i+j])
            vy_ref_j = vel_ref_y(dense_time_pt[i+j])
            vz_ref_j = vel_ref_z(dense_time_pt[i+j])
            yawr_ref_i = yawr_ref(dense_time_pt[i+j])
            yref = np.array([x_ref_j, y_ref_j, z_ref_j,  vx_ref_j, vy_ref_j, vz_ref_j,  1,0,0,0,  0,0,yawr_ref_i, 0, 0, mg, 0, 0, 0, 0, 0, 0])# changed qw to 1
            ###########################
            # if err_theshold<= 0.02:
            #     yref = np.array([*last_pose, 0.0, 0.0, 0.0, 1,0,0,0, 0,0,0, *u_ref ])
            # print(yref)
            # print(simX[i, :])

            #ipdb.set_trace()
            ###########################
            acados_solver.set(j, "p", yref)
        ###########################
        x_ref_j  = pos_ref_x(dense_time_pt[i+j])
        y_ref_j  = pos_ref_y(dense_time_pt[i+j])
        z_ref_j  = pos_ref_z(dense_time_pt[i+j])
        vx_ref_j = vel_ref_x(dense_time_pt[i+j])
        vy_ref_j = vel_ref_y(dense_time_pt[i+j])
        vz_ref_j = vel_ref_z(dense_time_pt[i+j])
        yawr_ref_i = yawr_ref(dense_time_pt[i+j])
        ###########################
        yref = np.array([x_ref_j, y_ref_j, z_ref_j,  vx_ref_j, vy_ref_j, vz_ref_j,  1,0,0,0,  0,0,yawr_ref_i,*u_ref])# changed qw to 1    
        acados_solver.set(N, "p", yref) 
        acados_solver.set(0, "lbx", simX[i, :])
        acados_solver.set(0, "ubx", simX[i, :])
        #solve ocp
        t = time.time()
        status = acados_solver.solve()
        if status != 0:
            print("acados returned status {} in closed loop iteration {}.".format(status, i))
        solve_elapsed = time.time() - t
        
        simU[i, : ] = acados_solver.get(0, "u") 


        #############################################
        F = simU[i,:3]
        M = simU[i,3:6]
        V = simU[i,6:9]
        quat = simX[i,6:10]
        R_mat = QuatToRot(quat)
        Fl = ca.mtimes(R_mat.T , F)
        Wl = ca.vertcat(Fl, M)
        print("Yref")
        print(yref)
        print("F")
        print(F)
        print("M")
        print(M)
        print("V")
        print(V)
        print("R_mat")
        print(R_mat)
        print("Wl")
        print(Wl)
        check_hlist_f = h_list_f(F,M,V,quat) 
        print("h_list")
        print(check_hlist_f) 
        print("P")
        print(payload_params.P)
        print("PseudoInv_P")
        print(payload_params.pseudo_inv_P)
        print("Null space")
        print(null_space(payload_params.P))
        mu_list = ca.mtimes(payload_params.pseudo_inv_P, Wl) - ca.mtimes(null_space(payload_params.P), V)
        print("mu_list")
        print(mu_list)
        rho_list = payload_params.rho_vec_list
        print("Rho")
        print(rho_list)
        cabel_length = payload_params.cable_length
        print("Cable Length")
        print(cabel_length)
        ##############################################
        
        print("simU")
        print(simU[i, : ])
        print(simU[i, : ].shape)
        cost = 0
        # print(acados_solver.get(0,"p"))
        # print("#############print Constraints###############################")
        # print(acados_solver)
        # for j in range(N):                        
        #     h_val = acados_solver.get(j, "lam")
        #     x_val = acados_solver.get(j, "x")
        #     print(x_val) 
        #     #print(model.con_h_expr(x_val))
        #     print("lh: ", h_val)            
        #     #print("uh", h_val[27:30])
        #     #ipdb.set_trace()  
        
        #u = np.array([-0.5,-0.5,2.8, 0,0,0,0,0,0])
        simX[i+1, : ] = acados_integrator.simulate(x = simX[i,:], u = simU[i, : ])
        print("simX")
        print(simX[i+1, : ])
        #sim_elapsed = time.time() - t
        t0 = t0 + Ts      
        
        if terminate_sim(simX[i+1, :],last_pose, err_theshold):
            print("breaking")
            break
    end_time = clock.now()
    print(Nsim)
    t_time = start_time - end_time
    print(t_time.nanoseconds / 1e9)
    #post processing - plotiing and print
    tracked_traj = simX[0:i+1, :]
    #ipdb.set_trace()
    plot_followed_traj(tracked_traj[:Nsim+1-N,0], tracked_traj[:Nsim+1-N,1],tracked_traj[:Nsim+1-N,2], pos_ref[0](time_points), pos_ref[1](time_points), pos_ref[2](time_points))
    t = np.linspace(0.0, Nsim+1-N, Nsim+1-N)
    #plotRes(simX, simU, t)
    plot_inputs(simU[:,0:3],simU[:,3:6],t)
    t = np.linspace(time_points[0], time_points[-1],NSim+1)
    plotPosVsTime(simX,pos_ref,t)
    # Print some statstime_points
    #print("Average speed:{}m/s".format(np.average(simX[:, 3])))
    print("Lap time: {}s".format(T))
    # avoid plotting when running on Travis
    if os.environ.get("ACADOS_ON_CI") is None:
        plt.show()



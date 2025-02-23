
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

def terminate_sim(simX,last_pose, threshold):
    dist = np.linalg.norm(simX[0:3] - last_pose )
    val = True if (dist <= threshold) else False   
    return val 


if __name__ == '__main__':
    nmpc_filename = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/payload_nmpc_params.yaml"
    #pl_filename = '/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/load_params/triangular_payload.yaml' 

    #**Case 1
    payload_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/load_params/triangular_payload.yaml"
    uav_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/uav_params/"
    mechanism_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/attach_mechanism/cable/3_robots_triangular_payload_0-5m.yaml"
    payload_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_cable_gains.yaml"
    uav_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/"

    read_params_funcs = read_params.read_params()
    payload_params, quad_params = read_params_funcs.system_setup(payload_params_path,uav_params_path,mechanism_params_path, payload_control_gain_path, uav_control_gain_path)
    control_params = read_params_funcs.read_pl_nmpc_params(nmpc_filename)
    
    model, acados_solver, acados_integrator = controller_setup(control_params, payload_params) 

    #read and track and interpolate
    track = 'tracks/trajectory.txt'
    [time_points, pos_ref, vel_ref, acc_ref, yaw_ref, yawr_ref, start_pose, last_pose ] = read_interpl(track)
    #visualize_traj(track)
    Tf = 1    # time step
    N = 10     # prediction horizon
    T = 7  # maximum simulation time[s]
    sref_N = 2  # reference for final reference progress
    Ts = Tf / N 
    Nsim = int(T /Ts)

    err_theshold = 0.005
    nx = model.x.rows()
    nu = model.u.rows()
    ny = nx + nu
    
    simX = np.zeros((Nsim+1, nx), dtype= float)
    simU = np.zeros((Nsim+1, nu), dtype= float)
    model.x0 = [start_pose[0],start_pose[1],start_pose[2], 0,0,0, 1,0,0,0, 0,0,0]
    simX[0,:] = model.x0
    #mg = model.mass * model.g
    mg = 0.250*9.81
    u_ref = np.array([0,0,mg, 0,0,0, 0,0,0]) 
    
    #simulation loop 
    t0 = 0 
    rclpy.init()
    
    clock = Clock()

    # Get the current time
    
    for i in range(Nsim):
        start_time = time.time()  

        for j in range(N):
            t_j = t0 + (j) * Ts
            x_ref_j = pos_ref[0](t_j)
            y_ref_j = pos_ref[1](t_j)
            z_ref_j = pos_ref[2](t_j)

            vx_ref_j = vel_ref[0](t_j)
            vy_ref_i = vel_ref[1](t_j)
            vz_ref_j = vel_ref[2](t_j)
            
            yaw_ref_i = yaw_ref(t_j)
            yawr_ref_i = yawr_ref(t_j)
            yref = np.array([x_ref_j, y_ref_j, z_ref_j,  vx_ref_j, vy_ref_i, vz_ref_j,  0,0,0,0,  0,0,yawr_ref_i, *u_ref])
            # print(yref)
            # print(simX[i, :])

            #ipdb.set_trace()
            acados_solver.set(j, "p", yref)
                  
        acados_solver.set(N, "p", yref) 
        acados_solver.set(0, "lbx", simX[i, :])
        acados_solver.set(0, "ubx", simX[i, :])

        simU[i, : ] = acados_solver.get(0, "u") 
        #solve ocp
        end_time = time.time()
        # status = acados_solver.solve()
        # if status != 0:
        #     print("acados returned status {} in closed loop iteration {}.".format(status, i))
        solve_elapsed = end_time - start_time
        print("solve_elapsed: ", solve_elapsed)
        ipdb.set_trace()
        
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
    t_time = start_time - end_time
    print(t_time.nanoseconds / 1e9)
    #post processing - plotiing and print
    tracked_traj = simX[0:i+1, :]
    #ipdb.set_trace()
    t = np.linspace(0.0, Nsim+1, Nsim+1)
    #plotRes(simX, simU, t)
    plot_followed_traj(tracked_traj[:,0], tracked_traj[:,1],tracked_traj[:,2], pos_ref[0](time_points), pos_ref[1](time_points), pos_ref[2](time_points))
    
    #plot_inputs(simU[:,0:3],simU[:,3:6],t)
    # Print some statstime_points
    #print("Average speed:{}m/s".format(np.average(simX[:, 3])))
    print("Lap time: {}s".format(T))
    # avoid plotting when running on Travis
    if os.environ.get("ACADOS_ON_CI") is None:
        plt.show()



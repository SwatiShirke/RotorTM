
import time, os
import numpy as np
from testing_pl_payload_controller import *
from plotFcn import *
from tracks.readDataFcn import read_interpl, visualize_traj
import matplotlib.pyplot as plt
from matplotlib.ticker import MaxNLocator
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
    model, acados_solver, acados_integrator, cbf_constraints = controller_setup(control_params, payload_params, obstacle_params, cbf_params, np.array(init_state), u_ref) 
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
    dist = []
    LAMB_list = []
    MU_list   = []
    CBF_Constraint = []

    # Get the current time
    start_time = clock.now()
    for i in range(Nsim):
          
        cbf_p, model_lamb_mu_omg = cbf_constraints.get_all_minimum_dist(cbf_params)
        LAMB_list.append(np.array(model_lamb_mu_omg[:6]))
        MU_list.append(np.array(model_lamb_mu_omg[6:]))
        print("CBF P: ",cbf_p)
        dist.append(cbf_p-cbf_params["margin"])
        lamb = model_lamb_mu_omg[:6]
        mu   = model_lamb_mu_omg[6:-1]
        mat_A, vec_b = cbf_constraints.obstacles[0].get_convex_rep()
        robot_G, robot_g = cbf_constraints.payload.get_convex_rep()

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

            acados_solver.set(j, "p", np.append(np.concatenate((yref,np.array(cbf_p).reshape(1,))), cbf_params["cbf_gamma"]**j))
            u_init = acados_solver.get(j,"u")
            acados_solver.set(j,"u",np.concatenate((u_init[:9],model_lamb_mu_omg)))

                  
        acados_solver.set(N, "p", np.append(np.concatenate((yref,np.array(cbf_p).reshape(1,))), cbf_params["cbf_gamma"]**N)) 
        acados_solver.set(0, "lbx", simX[i, :])
        acados_solver.set(0, "ubx", simX[i, :])

        #solve ocp
        t = time.time()
        status = acados_solver.solve()
        if status != 0:
            print("acados returned status {} in closed loop iteration {}.".format(status, i))
        solve_elapsed = time.time() - t
        
        simU[i, : ] = acados_solver.get(0, "u") 
        print("simU")
        print(simU[i, : ])
        print(simU[i, : ].shape)
        cost = 0
        
        simX[i+1, : ] = acados_integrator.simulate(x = simX[i,:], u = simU[i, : ])
        robot_T = simX[i+1,:3].reshape(3,1)
        robot_X = simX[i,:3].reshape(3,1)
        lamb    = simU[i,9:9+6].reshape(6,)
        mu      = simU[i,9+6:-1].reshape(5,)
        omega   = simU[i,-1]
        print("OMEGA",omega)
        print("CBF CONSTRAINT",-np.dot(robot_g.T, mu) + np.dot((np.dot(mat_A, robot_T) - vec_b).T, lamb)
                -cbf_params["cbf_gamma"] * (cbf_p - cbf_params["margin"]) - cbf_params["margin"])
        
        CBF_Constraint.append(-np.dot(robot_g.T, mu) + np.dot((np.dot(mat_A, robot_T) - vec_b).T, lamb)
                -cbf_params["cbf_gamma"] * (cbf_p - cbf_params["margin"]) - cbf_params["margin"])
        # print("CBF CONSTRAINT", np.linalg.norm(robot_T-np.array([[1.5],[1.5],[2]])) ** 2  -cbf_params["cbf_gamma"] *np.linalg.norm(robot_X-np.array([[1.5],[1.5],[2]])) ** 2)
        # CBF_Constraint.append(np.linalg.norm(robot_X-np.array([[1.5],[1.5],[2]])))
        # CBF_Constraint.append(np.sum((simX[i,:3]-np.array([[1],[1],[1.5]]) )** 2) - 1**2)
        cbf_constraints.set_state(simX[i+1,:], simU[i,:])
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

    #################################
    with open('Lambda.txt', 'w') as f:
        for arr in LAMB_list:
            np.savetxt(f, [arr], fmt='%s')
    with open('Mu.txt', 'w') as f:
        for arr in MU_list:
            np.savetxt(f, [arr], fmt='%s')
    #################################
    #post processing - plotiing and print
    tracked_traj = simX[0:i+1, :]
    #ipdb.set_trace()
    t = np.linspace(0.0, Nsim+1, Nsim+1)
    #plotRes(simX, simU, t)
    plot_followed_traj(tracked_traj[:,0], tracked_traj[:,1],tracked_traj[:,2], pos_ref[0](time_points), pos_ref[1](time_points), pos_ref[2](time_points))
    plt.plot(dist, label="Min dist")
    plt.title("Distance between PL and Obs")
    plt.xlabel("Index")
    plt.ylabel("dist")
    plt.gca().yaxis.set_major_locator(MaxNLocator(nbins=15))
    plt.plot(CBF_Constraint,label="constraint")
    plt.axhline(y=0, color='black', linestyle='--', linewidth=1)
    plt.legend()
    # plot.show()
    #plot_inputs(simU[:,0:3],simU[:,3:6],t)
    # Print some statstime_points 
    #print("Average speed:{}m/s".format(np.average(simX[:, 3])))
    print("Lap time: {}s".format(T))
    # avoid plotting when running on Travis
    if os.environ.get("ACADOS_ON_CI") is None:
        plt.show()




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

    # Get the current time
    start_time = clock.now()
    
    init_state = np.array([0,0,0, 0,0,0, 0,0,0,1, 0,0,0])
    init_input = u_ref = np.array([0,0,mg, 0,0,0, 0,0,0]) 

    cbf_constraints.set_state(init_state,init_input)
    cbf_constraints.get_all_minimum_dist(cbf_params)

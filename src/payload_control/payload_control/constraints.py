from rotor_tm_utils import utilslib 
import casadi as ca
from scipy.linalg import null_space
from utils import QuatToRot
import numpy as np
import ipdb
from casadi import Function
from rotor_tm_utils import read_params

def get_constraints(u, quat, payload_params, control_params, pyaload_pose):
    #F = Force vector in Intertial Frame
    #M = Moment vector in Payload frame
    #V = Null vector in Payload frame
    #quat = quaternions of payload rotation w.r.to inetial frame
    #R_mat = rotation matrix for payload to inertia 
    #mu_list = list of tension forces applied on each cable by k quadrotors
    #rho_list = list of rho vectors, pose of attached points in the pyaload frame
    #P_mat = 
    #N_mat = Null space matrix
    #constraint_th = a dictionary for distances used for inequlity constraints 
    #ex - min dist between between 2 quadrotors 
    F = u[0:3]
    M = u[3:6]
    V = u[6:9]


    #Null space exploitation
    P_mat = payload_params.P
    N_mat = null_space(P_mat)
    R_mat = QuatToRot(quat)    
    Fl = ca.mtimes(R_mat.T , F)

    
    #calulate wrench in payload frame
    Wl = ca.vertcat(Fl, M)
    mu_list = ca.mtimes(payload_params.pseudo_inv_P, Wl) - ca.mtimes(N_mat, V)
    rho_list = payload_params.rho_vec_list
    cabel_length = payload_params.cable_length
    quad_pose_list = cal_quad_pose(mu_list, rho_list, cabel_length)   # cal_quad_pose2(mu_list, rho_list, cabel_length)
    
    #calculate constarints
    quad_dist = control_params.dist_r
    obj_pl_dist = control_params.dist_OL
    obj_quad_dist = control_params.dist_Or
    h_list = cal_constarints(quad_pose_list, quad_dist)    # cal_constarints3(quad_pose_list, quad_dist)
    h_list_f = cal_constarints_2(quad_pose_list,F,M,V,quat) # cal_constarints_4(quad_pose_list,F,M,V,quat)

    #test simple constraint
    c_list = test_simple_constraints(F)
    return h_list, h_list_f

def test_simple_constraints(F):
    h_list = []
    h_list = ca.vertcat(h_list, 5, 4, 3, 4, 6, 101)
    # print("here now..")
    # print(h_list)
    return h_list
    

def cal_constarints(quad_pose_list, quad_dist):
    h_list = []     
    N_quad = len(quad_pose_list)
    #ipdb.set_trace()
    for i in range(N_quad - 1):
        for j in range(i +1 , N_quad):
            #h_list = ca.vertcat(h_list, (ca.norm_2(quad_pose_list[i] - quad_pose_list[j]) - quad_dist))
            difference = quad_pose_list[i] - quad_pose_list[j]
            diff = ca.SX(difference)
            dot_prod = ca.mtimes(difference.T,difference)
            h_list = ca.vertcat(h_list, dot_prod)
            #h_list.append(ca.norm_2(quad_pose_list[i] - quad_pose_list[j]) - quad_dist)
    return h_list

def cal_constarints3(quad_position, quad_dist):
    h_list = []     
    N_quad = quad_position.shape[0]
    print(N_quad)
    for i in range(N_quad - 1):
        for j in range(i +1 , N_quad):
            difference = quad_position[i] - quad_position[j]
            diff = ca.SX(difference)
            dot_prod = ca.mtimes(difference.T,difference)
            h_list = ca.vertcat(h_list, dot_prod)
    return h_list

def cal_constarints_2(quad_pose_list,F,M,V,quat):
    h_list = []     
    N_quad = len(quad_pose_list)
    #ipdb.set_trace()
    for i in range(N_quad - 1):
        for j in range(i +1 , N_quad):
            #h_list = ca.vertcat(h_list, (ca.norm_2(quad_pose_list[i] - quad_pose_list[j]) - quad_dist))
            difference = quad_pose_list[i] - quad_pose_list[j]
            diff = ca.SX(difference)
            dot_prod = ca.mtimes(difference.T,difference)
            h_list = ca.vertcat(h_list, dot_prod)
            #h_list.append(ca.norm_2(quad_pose_list[i] - quad_pose_list[j]) - quad_dist)
    dist_list = Function('dist_f', [F,M,V,quat], [h_list])
    return dist_list

def cal_constarints_4(quad_pose_list,F,M,V,quat):
    h_list = []     
    N_quad = quad_pose_list.shape[0]
    #ipdb.set_trace()
    for i in range(N_quad - 1):
        for j in range(i +1 , N_quad):
            #h_list = ca.vertcat(h_list, (ca.norm_2(quad_pose_list[i] - quad_pose_list[j]) - quad_dist))
            difference = quad_pose_list[i] - quad_pose_list[j]
            diff = ca.SX(difference)
            dot_prod = ca.mtimes(difference.T,difference)
            h_list = ca.vertcat(h_list, dot_prod)
            #h_list.append(ca.norm_2(quad_pose_list[i] - quad_pose_list[j]) - quad_dist)
    dist_list = Function('dist_f', [F,M,V,quat], [h_list])
    return dist_list

def create_p_mat(rho_list):
    mat = []
    for rho in rho_list:
        column = ca.vertcat(ca.eye((3)), skew_mat(rho))
        mat = ca.horzcat(mat,column )
    return mat


def skew_mat(rho):
    [w1, w2, w3] = rho
    mat = ca.vertcat(ca.horzcat(0, -w3, w2 ),
                     ca.horzcat(w3, 0, -w1),
                     ca.horzcat(-w2, w1, 0))
    return mat
    
def cal_quad_pose(mu_list, rho_list, cabel_length):
    mu_list = ca.reshape(mu_list, 3,3)
    quad_pose_list = []
    len = rho_list.shape[0]
    for i in range(len):
        #ipdb.set_trace()
        # mu = mu_list[i]
        mu = mu_list[:,i]
        # rho = rho_list[i]
        rho = rho_list[:,i]
        lk = cabel_length
        zeta = 1 * mu / (ca.norm_2(mu)+ 1e-6)
        quad_position = rho  + lk * zeta
        quad_pose_list.append(quad_position)
    return quad_pose_list

def cal_quad_pose2(mu_list, rho_list, cabel_length):
    mu_list = ca.reshape(mu_list, 3,3)
    N = rho_list.shape[0]
    quad_position = ca.SX.zeros(3, N)
    for i in range(0, N):
        None
        mu = mu_list[:, i]
        rho = rho_list[:,i]
        lk = cabel_length
        zeta = 1 * mu / (ca.norm_2(mu)+ ca.np.finfo(np.float64).eps)
        quad_position[:, i] = rho  + lk * zeta
    return quad_position


if __name__ == "__main__":
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
    rho_list = payload_params.rho_vec_list

    mu = ca.vertcat(ca.vertcat(-0.0536764, -0.0537002, 0.843096), ca.vertcat(-0.0536914, -0.053674, 0.833008), ca.vertcat(-0.0537065, -0.0537002, 0.83631))
    cabel_length = 0.5
    quad_pose = cal_quad_pose2(mu, rho_list, cabel_length)
    N_quad = quad_pose.shape[0]
    print(N_quad)


    # N_quad = 3
    # print(N_quad)
    # for i in range(N_quad - 1):
    #     for j in range(i +1 , N_quad):
    #         difference = quad_pose[i] - quad_pose[j]
    #         print(difference.T.shape)
    #         print(difference.shape)
    #         print(ca.mtimes(difference.T,difference))
    #         diff = ca.SX(difference)
    #         dot_prod = ca.mtimes(difference.T,difference)
    #         h_list = ca.vertcat(h_list, dot_prod)
    # print(type(rho_list))
    # print(type(mu))
    # print(quad_pose)
    # print(type(quad_pose))



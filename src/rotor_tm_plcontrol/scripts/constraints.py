from rotor_tm_utils import utilslib 
import casadi as ca
from scipy.linalg import null_space
from utils import QuatToRot
import numpy as np
import ipdb
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
    quad_pose_list = cal_quad_pose(mu_list, rho_list, cabel_length)
    
    #calculate constarints
    quad_dist = control_params.dist_r
    obj_pl_dist = control_params.dist_OL
    obj_quad_dist = control_params.dist_Or
    h_list = cal_constarints(quad_pose_list, quad_dist)
    return h_list


def cal_constarints(quad_pose_list, quad_dist):
    h_list = []     
    N_quad = len(quad_pose_list)
    #ipdb.set_trace()
    for i in range(N_quad - 1):
        for j in range(i +1 , N_quad):
            h_list = ca.vertcat(h_list, (ca.norm_2(quad_pose_list[i] - quad_pose_list[j]) - quad_dist))
            #h_list.append(ca.norm_2(quad_pose_list[i] - quad_pose_list[j]) - quad_dist)
    return h_list



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
    len = rho_list.shape
    for i in range(len[0]):
        #ipdb.set_trace()
        mu = mu_list[i]
        rho = rho_list[i]
        lk = cabel_length
        zeta = 1 * mu / ca.norm_2(mu)
        quad_position = rho  + lk * zeta
        quad_pose_list.append(quad_position)
    return quad_pose_list





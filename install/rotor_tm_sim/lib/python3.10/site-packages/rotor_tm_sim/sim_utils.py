import numpy as np
import numpy.linalg as linalg
from rotor_tm_utils import utilslib, rosutilslib

def ptmassslackToTaut(t, x):
    # DESCRIPTION:
    # event function for point mass scenario dynammics 
    # if event is reached by ivp solver, it will switch from slack to taut, takes in t (time) and state (x)

    # INPUTS:
    # t             - time
    # x             - state of the point mass system. Specifically,
    #                 x is a 26 by 1 ndarray,
    #                                                               Name                 Last Element Location (counting from 1) 
    #                 x = np.array([ppx,  ppy,    ppz,            # payload position    3
    #                               pvx,  pvy,    pvz,            # payload velocity    6
    #                                pu,   pi,     pj,     pk,    # payload quat        10
    #                               pwx,  pwy,    pwz,            # payload omega       13
    #                               qpx,  qpy,    qpz,            # quad rotor position 16
    #                               qvx,  qvy,    qvz,            # quad rotor velocity 19 
    #                                qu,   qi,     qj,     qk,    # quad rotor quat     23
    #                               qwx,  qwy,    qwz])           # quad rotor omega    26

    # OUTPUTS:
    # value         - a float that determines taut condition
    value = np.linalg.norm(x[0:3] - x[13:16]) - ptmassslackToTaut.cable_length
    return value

def ptmasstautToSlack(t, x):
    # DESCRIPTION:
    # event function for point mass scenario dynammics 
    # if event is reached by ivp solver, it will switch from taut to slack, takes in t (time) and state (x)

    # INPUTS:
    # t             - time
    # x             - state of the point mass system. Specifically,
    #                 x is a 26 by 1 ndarray,
    #                                                               Name                 Last Element Location (counting from 1) 
    #                 x = np.array([ppx,  ppy,    ppz,            # payload position    3
    #                               pvx,  pvy,    pvz,            # payload velocity    6
    #                                pu,   pi,     pj,     pk,    # payload quat        10
    #                               pwx,  pwy,    pwz,            # payload omega       13
    #                               qpx,  qpy,    qpz,            # quad rotor position 16
    #                               qvx,  qvy,    qvz,            # quad rotor velocity 19 
    #                                qu,   qi,     qj,     qk,    # quad rotor quat     23
    #                               qwx,  qwy,    qwz])           # quad rotor omega    26

    # OUTPUTS:
    # value         - a float that determines slack condition
    value = np.linalg.norm(x[0:3] - x[13:16]) - ptmasstautToSlack.cable_length + 0.000001
    return value

def cooperativeGuard(t, x, nquad, slack_condition, rho_vec_list, cable_length, id):
    # DESCRIPTION:
    # Event function event function for cooperative dynamics
    # Each MAV in the simulation will have its own event function
    # This function will be called under a lambda handle
    
    # INPUTS:
    # t                 - time
    # x                 - (13 + 13*nquad) x 1,
    #                   state vector = [xL, yL, zL, xLd, yLd, zLd, 
    #                                 qLw, qLx, qLy, qLz, pL, qL, rL, 
    #                                 [xQ, yQ, zQ, xQd, yQd, zQd]_i, i = 1,...,nquad
    #                                 [qw, qx, qy, qz, pQ, qQ, rQ]_i, i = 1,...,nquad
    # nquad             - number of quads
    # slack_condition   - a size nquad array, denoting cable condition for each MAV
    # rho_vec_list      - a nquad by nquad matrix, denoting mounting position for each MAV
    # cable_length      - The cable's length
    # id                - a scalar, denoting the current MAV number

    # OUTPUTS:
    # value         - (attach points - robot distance) - cable_length

    # find the idx of the cables that are slack
    idx = np.arange(1, nquad+1)
    slack_cable_idx = idx[slack_condition == 1]
    taut_cable_idx = idx[slack_condition == 0]

    # The rotation matrix of the payload
    RotL = utilslib.QuatToRot(x[6:10])

    # The attach points' positions correspond to the slack cables. 
    attach_pts = x[0:3].reshape((3,1)) + RotL @ rho_vec_list

    # The quadrotor positions correspond to the slack cables. 
    slack_quad_pos_idx = 13*slack_cable_idx + np.array([[0],[1],[2]])
    taut_quad_pos_idx = 13*taut_cable_idx + np.array([[0],[1],[2]])

    # Set up the condition to terminate the integration.
    # Detect cable-robot distance = 0
    left = np.linalg.norm(x[slack_quad_pos_idx] - attach_pts[:,slack_cable_idx - 1],2,0)-cable_length[slack_cable_idx - 1]
    right = np.linalg.norm(x[taut_quad_pos_idx] - attach_pts[:,taut_cable_idx - 1],2,0)-cable_length[taut_cable_idx - 1] + 0.0001
    value = np.transpose(np.hstack((left, right)))
    return value[id]
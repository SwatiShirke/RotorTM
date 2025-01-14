
import numpy as np
import ipdb
import casadi as ca

def cal_square_cost(state_vec, ref_vec, weights):
    #all inpu arrays are np array (n)
    # print(weights)
    # print((ref_vec - state_vec)**2)
    cost = ca.dot((ref_vec - state_vec)**2, weights)
    #ipdb.set_trace()    
    return cost


def calc_quat_cost(q2, q1, weights ):
    #print(q2.size())
    #calculate quaternion difference 
    q_aux = np.array([
        q2[0] * q1[0] + q2[1] * q1[1] + q2[2] * q1[2] + q2[3] * q1[3],  # w
        q2[0] * q1[1] - q2[1] * q1[0] - q2[2] * q1[3] + q2[3] * q1[2],  # x
        q2[0] * q1[2] + q2[1] * q1[3] - q2[2] * q1[0] - q2[3] * q1[1],  # y
        q2[0] * q1[3] - q2[1] * q1[2] + q2[2] * q1[1] - q2[3] * q1[0],  # z
    ])
    #yaw rotation extraction
    q_att_denom = ca.sqrt(q_aux[0] * q_aux[0] + q_aux[3] * q_aux[3] + 1e-3)
    q_att = ca.vertcat(
    q_aux[0] * q_aux[1] - q_aux[2] * q_aux[3],
    q_aux[0] * q_aux[2] + q_aux[1] * q_aux[3],
    q_aux[3]) / q_att_denom
    result = ca.transpose(q_att) @ ca.diag(weights) @ q_att
    #ipdb.set_trace()
    return result


if __name__ == "__main__":
    vec =ca.vertcat(1,2,3)
    vec2 = ca.vertcat(4,5,6)    
    W = ca.vertcat(0.5,0.5,0.5)
    #res = (vec - vec2)**2 * W
    res2 = cal_square_cost(vec, vec2, W )
    print(res2)
    ipdb.set_trace()


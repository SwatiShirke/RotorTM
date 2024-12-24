
import numpy as np
import ipdb
import casadi as ca

def cal_square_cost(ref_vec, state_vec, weights):
    #all inpu arrays are np array (n)
    # print(weights)
    # print((ref_vec - state_vec)**2)
    cost = ca.dot((ref_vec - state_vec)**2, weights)
    #ipdb.set_trace()    
    return cost


if __name__ == "__main__":
    vec =ca.vertcat(1,2,3)
    vec2 = ca.vertcat(4,5,6)    
    W = ca.vertcat(0.5,0.5,0.5)
    #res = (vec - vec2)**2 * W
    res2 = cal_square_cost(vec, vec2, W )
    print(res2)
    ipdb.set_trace()


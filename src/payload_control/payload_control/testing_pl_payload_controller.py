from acados_template import AcadosOcp, AcadosOcpSolver, AcadosSimSolver
import casadi as ca
import numpy as np
# from payload_control.payload_model import payload_model
from payload_control.testing_pl_payload_model import payload_model
from rotor_tm_utils import QuatToYPR
from rotor_tm_utils import read_params
import sys
from cost_functions import cal_square_cost, calc_quat_cost
import ipdb
from constraints import get_constraints
from CBF_payload_constraints import Obs, TriangleObs, get_pl_obs_constraints
import sys
from testing_pl_cbf_class import CBFDualityOptimization
import os

def controller_setup(control_params,  payload_params, obstacle_params, cbf_params, init_state, init_input):
    #read yaml file   
    #MPC Key parameters
    N = control_params.N
    Tf = control_params.Tf 

    #constaints limits
    pl_max_vel = control_params.pl_max_vel
    pl_min_vel = control_params.pl_min_vel
    pl_max_omega = control_params.pl_max_omega
    pl_min_omega = control_params.pl_min_omega

    #define optimization problem
    ocp = AcadosOcp()
    model = payload_model(payload_params, cbf_params, obstacle_params)
    ocp.model = model
    ocp.dims.np = ocp.model.p.size()[0]
    ocp.parameter_values = np.zeros(ocp.dims.np)

    ##cost functions and references
    #turing matrices Q, R and Qe
    #states considered - pos, angle(rpy), linear vel, angular vel (12 x 1)
    #system states = pos, quaternions, linear vel, angular vel (13 x 1)
    #to handle mimatch between refence and model state, we convert quaternions to ypr and formulating new state vector
    #using new state vector for cost calculations
    Q_mat =  ca.vertcat(10,10,10, 10, 10, 10, 1e-4, 1e-4, 1e-4, 1e-4,  1e-4, 1e-4, 1)
    R_mat =  ca.vertcat(1e-3, 1e-3, 1e-3, 10, 10, 10, 1e-2, 1e-2, 1e-2)
    Q_emat = ca.vertcat(10,10,10, 10, 10, 10, 1e-4, 1e-4, 1e-4, 1e-4,  1e-4, 1e-4, 1)
    
    x_array = model.x
    u_aaray = model.u
    ref_array = model.p
    
    ##Some setup for the constraints
    cbf_constraints = CBFDualityOptimization(payload_params,obstacle_params["obstacles"], ref_array)
    hlist, hlist_lb, hlist_ub = cbf_constraints.setup(cbf_params,init_state, init_input, x_array, u_aaray)
    n_obs       = len(obstacle_params["obstacles"].keys())
    len_lambda  = cbf_params["lambda"]
    len_mu      = cbf_params["mu"]
    n_quad      = payload_params.nquad
    total_param = n_obs*(len_lambda + len_mu + 1) # + n_obs*n_quad*(len_lambda + len_lambda + 1) + n_quad*(len_lambda + len_lambda + 1)
    zeros_param = np.zeros(total_param)
    ones_param  = 10*np.ones(total_param)
    idxs_param  = np.arange(9, total_param + 9)
    

    #calculate square cost    
    ocp.cost.cost_type = 'EXTERNAL'  
    pos_err    = cal_square_cost(x_array[0:3], ref_array[0:3], Q_mat[0:3])
    vel_err    = cal_square_cost(x_array[3:6], ref_array[3:6], Q_mat[3:6])
    quat_error = calc_quat_cost(x_array[6:10], ref_array[6:10], Q_mat[6:9])    
    input_err  = cal_square_cost(u_aaray[:9], ref_array[13:22], R_mat)
    ocp.model.cost_expr_ext_cost = pos_err + vel_err + quat_error + input_err 
    ocp.model.cost_expr_ext_cost_0 = pos_err + vel_err + quat_error + input_err 
    

    #terminal cost
    ocp.cost.cost_type_e = 'EXTERNAL'
    pos_err    = cal_square_cost(x_array[0:3], ref_array[0:3], Q_emat[0:3])
    vel_err    = cal_square_cost(x_array[3:6], ref_array[3:6], Q_emat[3:6])
    quat_error = calc_quat_cost(x_array[6:10], ref_array[6:10], Q_emat[6:9])        
    ocp.model.cost_expr_ext_cost_e = pos_err + vel_err + quat_error
    
    ##constraints
    #input constraints
    ocp.constraints.lbu   = np.concatenate((np.array([-10,-10,0, -10,-10,-10]),zeros_param))
    ocp.constraints.ubu   = np.concatenate((np.array([20,20,20,10,10,10]),ones_param))
    ocp.constraints.idxbu = np.concatenate((np.array([0,1,2,3,4,5]),idxs_param))
    
    #initial state contraints
    ocp.constraints.x0 = np.array([0.0, 0, 0,  0, 0, 0,  1, 0,  0, 0,  0, 0, 0 ] )

    #lower and upper bound constraints on states - velocity and angular velocities
    ocp.constraints.lbx   = np.array([pl_min_vel, pl_min_omega]).flatten()
    ocp.constraints.ubx   = np.array([pl_max_vel, pl_max_omega]).flatten()
    ocp.constraints.idxbx = np.array([ 3,4,5, 10,11,12])
    
    # ##inequlity constraints
    ## u = model.u
    ## h_list = get_constraints(u, quat, payload_params, control_params ,x_val[0:3] )
    ocp.model.con_h_expr = hlist
    ocp.dims.nh          = hlist.shape[0]
    ocp.constraints.lh   = hlist_lb          # lower bound
    ocp.constraints.uh   = hlist_ub            # Upper bound 
    ocp.model.lh         = np.zeros((hlist.shape[0], 1))          # lower bound
    ocp.model.uh         = 5000 * np.ones((hlist.shape[0], 1)) 

    # #payload obstacle constraints
    # obs1 = Obs(1,1,1, 0.5,0.5,0.5)
    # payload = TriangleObs()
    # A_pl, B_pl = payload.get_convex_rep()
    # A_obs, B_obs = obs1.get_convex_rep() 
    # h_list = get_pl_obs_constraints(A_obs, B_obs, A_pl, B_pl)     
    # ocp.model.con_h_expr =h_list
    # ocp.dims.nh = h_list.shape[0]
    # ocp.constraints.lh = np.zeros((h_list.shape[0], 1))          # lower bound
    # ocp.constraints.uh = 1 * np.ones((h_list.shape[0], 1))            # Upper bound 
    # ocp.model.lh = np.zeros((h_list.shape[0], 1))          # lower bound
    # ocp.model.uh = 1 * np.ones((h_list.shape[0], 1)) 



    ##controller settings
    ocp.solver_options.N_horizon             = N
    ocp.solver_options.tf                    = Tf
    ocp.solver_options.qp_solver             = 'PARTIAL_CONDENSING_HPIPM' # FULL_CONDENSING_QPOASES
    ocp.solver_options.nlp_solver_type       = 'SQP_RTI'                      #'SQP_RTI'
    ocp.solver_options.hessian_approx        = "EXACT"
    ocp.solver_options.integrator_type       = "ERK"
    ocp.solver_options.sim_method_num_stages = 4
    ocp.solver_options.regularize_method     = 'CONVEXIFY'
    ocp.solver_options.levenberg_marquardt   = 10.0

    ocp.solver_options.print_level           = 2
    
    ##create solver, integrator
    solver_json       = 'acados_ocp_' + model.name + '.json'
    acados_solver     = AcadosOcpSolver(ocp, json_file = solver_json,build=True)
    acados_integrator = AcadosSimSolver(ocp, json_file = solver_json, build=True)

    return model, acados_solver, acados_integrator, cbf_constraints

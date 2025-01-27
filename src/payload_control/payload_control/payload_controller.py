#from acados_template import AcadosOcp, AcadosOcpSolver, AcadosSimSolver
import casadi as ca
import numpy as np
from payload_model import payload_model
# from rotor_tm_utils import QuatToYPR
# from rotor_tm_utils import read_params
import sys
from cost_functions import cal_square_cost, calc_quat_cost
import ipdb
from constraints import get_constraints
from rotor_tm_utils import read_params


import sys
import os

# Add Acados library path to the system path for Python imports
#acados_lib_path = os.getenv('LD_LIBRARY_PATH', '')
os.environ['LD_LIBRARY_PATH'] = "/home/dhruv/acados/lib" 
LD_LIBRARY_PATH="/home/dhruv/acados/lib"
sys.path.append("/home/dhruv/acados/lib" )
sys.path.append('/home/dhruv/acados/python')
sys.path.append("/home/dhruv/acados" )
#acados_source_dir = os.getenv('ACADOS_SOURCE_DIR', '/home/swati/acados')

# Now you can import the Acados Python bindings
from acados_template import AcadosOcp, AcadosOcpSolver, AcadosSimSolver

def controller_setup(control_params,  payload_params):
    #read yaml files
    # pay_load_param_path = sys.argv[1]
    # nmpc_control_path = sys.argv[2]    
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
    model = payload_model(payload_params)
    ocp.model = model
    ocp.dims.np = ocp.model.p.shape[0]# changed size() to shape
    ocp.parameter_values = np.zeros(ocp.dims.np)
    nx = model.x.rows()
    nu = model.u.rows()
    ny = nx + nu
    unscale = N/Tf

    ##cost functions and references
    #turing matrices Q, R and Qe
    #states considered - pos, angle(rpy), linear vel, angular vel (12 x 1)
    #system states = pos, quaternions, linear vel, angular vel (13 x 1)
    #to handle mimatch between refence and model state, we convert quaternions to ypr and formulating new state vector
    #using new state vector for cost calculations
    Q_mat =  ca.vertcat(10,10,10, 10, 10, 10, 1e-4, 1e-4, 1e-4, 1e-4,  1e-4, 1e-4, 1)
    R_mat =  ca.vertcat(10, 10, 10, 10, 10, 10, 1e-2, 1e-2, 1e-2)
    Q_emat = ca.vertcat(100,100,100, 100, 100, 100, 1e-4, 1e-4, 1e-4, 1e-4,  1e-4, 1e-4, 1)
    # Q_mat =  ca.vertcat(1000,1000,1000, 1000, 1000, 1000, 1e-4, 1e-4, 1e-4, 1e-4,  1e-4, 1e-4, 1)
    # R_mat =  ca.vertcat(10, 10, 10, 10, 10, 10, 1e-2, 1e-2, 1e-2)
    # Q_emat = ca.vertcat(90000,90000,90000, 1000, 1000, 1000, 1e-4, 1e-4, 1e-4, 1e-4,  1e-4, 1e-4, 1)
    Q_emat = 1*Q_emat
    Q_mat = 1*Q_mat
    #ipdb.set_trace()
    #path cost
    x_val = model.x
    quat = x_val[6:10] #[3:7]  
    # y,p,r = QuatToYPR.QuatToYPR(quat)
    # x_array = ca.vertcat(x_val[0:3],r,p,y, x_val[7:10], x_val[10:13] )
    x_array = model.x
    u_aaray = model.u
    ref_array = model.p
    #print(ref_array)

    #calculate square cost    
    ocp.cost.cost_type = 'EXTERNAL'  
    pos_err = cal_square_cost(x_array[0:3], ref_array[0:3], Q_mat[0:3])
    vel_err = cal_square_cost(x_array[3:6], ref_array[3:6], Q_mat[3:6])
    quat_error = calc_quat_cost(x_array[6:10], ref_array[6:10], Q_mat[6:9])
    input_err = cal_square_cost(u_aaray, ref_array[13:22], R_mat)
    ocp.model.cost_expr_ext_cost = pos_err + vel_err + quat_error + input_err 
    ocp.model.cost_expr_ext_cost_0 = pos_err + vel_err + quat_error + input_err 
    

    #terminal cost
    ocp.cost.cost_type_e = 'EXTERNAL'
    pos_err = cal_square_cost(x_array[0:3], ref_array[0:3], Q_emat[0:3])
    vel_err = cal_square_cost(x_array[3:6], ref_array[3:6], Q_emat[3:6])
    quat_error = calc_quat_cost(x_array[6:10], ref_array[6:10], Q_emat[6:9])        
    ocp.model.cost_expr_ext_cost_e = pos_err + vel_err + quat_error
    
    ##constraints
    #input constraints
    # mg = 0.250*9.81 # 0.25 is the wrong mass value check the params file
    ocp.constraints.constr_type = 'BGH'
    ocp.constraints.lbu = np.array([-10,-10,-10, -10,-10,-10 , -10,-10,-10]) #np.array([-10,-10,-10, -10,-10,-10])
    ocp.constraints.ubu = np.array([20,20,20,10,10,10,10,10,10]) #np.array([20,20,20,10,10,10])
    ocp.constraints.idxbu = np.array([0,1,2,3,4,5,6,7,8]) #np.array([0,1,2,3,4,5])
    
    #initial state contraints
    ocp.constraints.x0 = np.array([0.0, 0, 0,  0, 0, 0,  1, 0,  0, 0,  0, 0, 0 ] )

    #lower and upper bound constraints on states - velocity and angular velocities
    ocp.constraints.lbx = np.array([pl_min_vel, pl_min_omega]).flatten()
    ocp.constraints.ubx = np.array([pl_max_vel, pl_max_omega]).flatten()
    ocp.constraints.idxbx = np.array([ 3,4,5, 10,11,12])

    # ##inequlity constraints
    u = model.u
    h_list, hlist_f = get_constraints(u, quat, payload_params, control_params ,x_val[0:3] )
    ocp.model.con_h_expr = h_list
    ocp.dims.nh = h_list.shape[0]
    
    # obstacle = ca.vertcat(1.5,1.5,2)
    # diff = obstacle - x_array[0:3]
    # distance = diff.T@diff
    # j = distance - 1**2
    # h_list = j
    # ocp.model.con_h_expr = j 
    # ocp.dims.nh = j.shape[0]





    # # ocp.constraints.lh = np.zeros((h_list.size1(), 1))  #       #lower bound
    # # ocp.constraints.uh = 200 * np.ones((h_list.size1(), 1))            # Upper bound 
    # # ocp.model.lh = np.zeros((h_list.size1(), 1))          # lower bound
    # # ocp.model.uh = 1 * np.ones((h_list.size1(), 1))  

    ocp.cost.zl = 100*np.ones((h_list.size1(),))
    ocp.cost.Zl = 100*np.ones((h_list.size1(),))

    ocp.cost.zu = 100*np.ones((h_list.size1(),))
    ocp.cost.Zu = 100*np.ones((h_list.size1(),))

    # ##### Lower and upper limits
    ocp.constraints.lh = 0.0*np.ones((h_list.size1()))
    ocp.constraints.uh = 2.0 * np.ones((h_list.size1()))
    ocp.constraints.lsh = np.zeros((h_list.size1()))
    ocp.constraints.ush = np.zeros((h_list.size1()))
    ocp.constraints.idxsh = np.array(range(h_list.size1()))
    
    # print(ocp.constraints.lbu.shape)
    # print(ocp.constraints.lbx.shape)
    # print(ocp.constraints.lg.shape)
    # print(ocp.constraints.lh.shape)
    # print(ocp.constraints.lphi.shape)
    # print(ocp.constraints.ubu.shape)
    # print(ocp.constraints.ubx.shape)
    # print(ocp.constraints.ug.shape)
    # print(ocp.constraints.uh.shape)
    # ipdb.set_trace() 

    ##controller settings
    ocp.solver_options.N_horizon = N
    ocp.solver_options.tf = Tf
    ocp.solver_options.qp_solver = 'PARTIAL_CONDENSING_HPIPM' # FULL_CONDENSING_QPOASES
    ocp.solver_options.nlp_solver_type = 'SQP_RTI'
    ocp.solver_options.hessian_approx = "EXACT"
    ocp.solver_options.integrator_type = "ERK"
    ocp.solver_options.sim_method_num_stages = 4
    ocp.solver_options.regularize_method = 'CONVEXIFY'
    ocp.solver_options.levenberg_marquardt = 10.0
    
    ##create solver, integrator
    solver_json = 'acados_ocp_' + model.name + '.json'
    acados_solver = AcadosOcpSolver(ocp, json_file = solver_json)
    acados_integrator = AcadosSimSolver(ocp, json_file = solver_json)

    return model, acados_solver, acados_integrator, hlist_f

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
    control_params = read_params_funcs.read_pl_nmpc_params(nmpc_filename)
    a,b,c,d = controller_setup(control_params,payload_params)
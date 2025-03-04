from acados_template import AcadosOcp, AcadosOcpSolver, AcadosSimSolver
from acados_template import AcadosModel
from payload_control.payload_model import payload_model
import numpy as np
import yaml 
import casadi as ca

class Obs:
    def __init__(self,origin_x,origin_y,origin_z,length,breadth,height):
        self.origin_x = origin_x
        self.origin_y = origin_y
        self.origin_z = origin_z
        self.length = length
        self.breadth = breadth
        self.height = height

    def get_convex_rep(self):
        A = np.array([[0,0,1], [0,0,-1], [1,0, 0], [-1,0, 0],[0,1,0],[0,-1,0]])
        B = np.array([[self.origin_z+self.height/2],[-self.origin_z+self.height/2], [self.origin_x+self.length/2], [-self.origin_x+self.length/2],[self.origin_y+self.breadth/2],[-self.origin_y+self.breadth/2]])
        return A, B


class TriangleObs:
    def get_convex_rep(self):
        A = np.array([[0,0,1],[0,0,-1],[1.73,3,0],[-3.47,0,0],[1.73,-3,0]])
        B = np.array([[0.05],[0.05],[1],[1],[1]])
        return A,B  


def dummy_model(nu):
    model_name = "CBF_payload_obs"
    x = ca.SX.sym("x")
    x_dot = ca.SX.sym("x_dot")
    u = ca.SX.sym("u", nu)
    p = ca.SX.sym("p", 0)

    f_expl = {x}
    f_impl = x_dot - f_expl
    model = AcadosModel()
    model.name = model_name
    model.expl_expr = f_expl
    model.impl_expr = f_impl
    model.x = x
    model.x_dot = x_dot
    model.u = u
    model.p = p 
    nx = model.x.rows()
    nu = model.u.rows()
    return model


class cbf_payload_obs():
    def __init__(self, A_pl, B_pl, A_obs, B_obs, d_safe):
        """
        A_pl - A mat of payload 6 by 3
        A_obj - A mat of an obstacle 6 by 3
        B_pl - B mat pf payload, 3 by 1
        B_obj - B mat of obstacle 3 by 1
        """
        self.ocp = AcadosOcp()
        self.nu = A_pl.shape[-1] + A_obs.shape[-1]        
        self.ocp.model = dummy_model(self.nu)
        

        #set dimensions
        self.N = 1
        self.tf = 1.0
        # self.ocp.dims.nx = 1
        # self.ocp.dims.nu = self.nu 
        self.ocp.dims.N = self.N  #optimization is static, only for 1 step

        # Define symbolic variables
        

        #set cost functions and lower and upper bound on optimization var
        u = self.ocp.model.u 
        self.ocp.model.cost_expr_ext_cost = ((u[0] -u[3])**2 + (u[1]- u[4])**2 + (u[2] - u[5])**2) - d_safe**2
        self.ocp.constraints.lbu = np.array([-100, -100, 0])
        self.ocp.constraints.ubu = np.array([100,100,100])
        self.ocp.constraints.idxbu = np.array([0,1,2])

        
        #set inequlity constraints
        h_list = self.get_polytope_constraints()        
        self.ocp.model.con_h_expr = h_list
        self.ocp.dims.nh = h_list.shape[0]
        self.ocp.constraints.lh = np.zeros(h_list.shape[0])
        # ocp.constraints.uh = np.zeros(h_list.shape[0])

        #solver settings
        self.ocp.solver_options.N_horizon = self.N
        self.ocp.solver_options.tf = self.tf
        self.ocp.solver_options.qp_solver = 'PARTIAL_CONDENSING_HPIPM' # FULL_CONDENSING_QPOASES
        self.ocp.solver_options.nlp_solver_type = 'SQP_RTI'
        self.ocp.solver_options.hessian_approx = "EXACT"
        self.ocp.solver_options.integrator_type = "ERK"
        self.ocp.solver_options.sim_method_num_stages = 4
        self.ocp.solver_options.regularize_method = 'CONVEXIFY'
        self.ocp.solver_options.levenberg_marquardt = 10.0

        ##create solver, integrator
        solver_json = 'acados_ocp_' + self.ocp.model.name + '.json'
        self.acados_solver = AcadosOcpSolver(self.ocp, json_file = solver_json)
        #acados_integrator = AcadosSimSolver(self.ocp, json_file = solver_json)


    def get_polytope_constraints(self):
        h_list = []

        return np.array(h_list)

    def optimize_cbf(self, B_pl, B_obj):
        self.B_pl = B_pl
        self.B_obj = B_obj
        status = self.acados_solver.solve()        
        if status != 0:
            print("acados returned status. ".format(status))
        u_min = self.acados_solver.get(0, "u") 
        point1 = u_min[0:3]
        point2 = u_min[3:6]
        dist = ca.norm_2(point1 - point2)
        return dist 

def get_h_x0(A_obs, B_obs, A_pl , B_pl):
    opti = ca.Opti()
    point1 = opti.variable(A_obs.shape[-1],1)
    point2 = opti.variable(A_pl.shape[-1],1)
    cost= 0
    const1 = A_obs@point1<=B_obs
    const2 = A_pl@point2<=B_pl
    opti.subject_to(const1)
    opti.subject_to(const2)

    dist_vec = point1-point2
    cost += dist_vec.T@dist_vec

    opti.minimize(cost)
    option = {"verbose": False, "ipopt.print_level": 0, "print_time": 0} 
    opti.solver("ipopt",option)

    opt_sol = opti.solve()
    dist = opt_sol.value(ca.norm_2(dist_vec))
        
    if dist>0:
        lamb = opt_sol.value(opti.dual(const1))/2*dist 
        mu = opt_sol.value(opti.dual(const2))/2*dist         
    else:
        dist=-1
        lamb = np.zeros(shape = (A_obs.shape[0],))
        mu = np.zeros(shape=(A_pl.shape[0],)) 
    return dist,lamb,mu 


def get_pl_obs_constraints(A_obs, B_obs, A_pl , B_pl):
    dist,lamb_obs,lamb_pl = get_h_x0(A_obs, B_obs, A_pl , B_pl)
    h_list = []
    h_list = ca.vertcat(h_list, lamb_obs)
    h_list = ca.vertcat(h_list, lamb_pl)    
    return h_list 

def simulate_x_next():
    """This function simulate system dynamics to find X(i+1) using system dynamics. 
    These values of X(i+1) used in constraints"""
    

    
if __name__ == "__main__":
    d_safe = 1
    obs1 = Obs(5,5,5,0.01,0.01,0.01)
    obs2 = Obs(6,6,6,0.01,0.01,0.01)
    payload = TriangleObs()
    A_pl, B_pl = payload.get_convex_rep()
    A_obs, B_obs = obs1.get_convex_rep() 
    h_list = get_pl_obs_constraints(A_obs, B_obs, A_pl, B_pl)
    














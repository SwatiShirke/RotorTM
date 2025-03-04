from acados_template import AcadosOcp, AcadosOcpSolver, AcadosSimSolver
from acados_template import AcadosModel
from payload_control.payload_model import payload_model
import numpy as np
import yaml 
import casadi as ca
from constraints_utils import Obs, TriangleObs, Payload_ODE

from rotor_tm_utils import read_params 


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

    solver = opti.to_function("solver", [], [opti.solve().value(ca.norm_2(dist_vec))])
    solver.generate("solver.cpp")

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

def simulate_x_next(X, U, params):
    """This function simulate system dynamics to find X(i+1) using system dynamics. 
    These values of X(i+1) used in constraints"""
    X_next = Payload_ODE(X,U,params)
    return X_next
  

    
if __name__ == "__main__":
    #for testing
    d_safe = 1
    obs1 = Obs(5,5,5,0.01,0.01,0.01)
    obs2 = Obs(6,6,6,0.01,0.01,0.01)
    payload = TriangleObs()
    A_pl, B_pl = payload.get_convex_rep()
    A_obs, B_obs = obs1.get_convex_rep() 
    h_list = get_pl_obs_constraints(A_obs, B_obs, A_pl, B_pl)

    
    














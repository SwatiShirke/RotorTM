#from casadi import ca.SX, ca.vertcat, sin, cos, Function, tan,  DM, horzcat, inv, cross, mtimes
import casadi as ca
import numpy as np
import ipdb
import yaml
from acados_template import AcadosModel
from rotor_tm_utils import read_params
from rotor_tm_utils import utilslib


def CaQuatToRot(q):
    """
    Converts a quaternion to a rotation matrix using CasADi.
    
    Args:
    - q: casadi.SX or MX (4x1 symbolic quaternion, with q = [qw, qx, qy, qz].T)

    Returns:
    - Rotation matrix (3x3 symbolic matrix)
    """
    # Step 1: Normalize the quaternion
    q = q / ca.sqrt(ca.sumsqr(q))

    # Step 2: Create the skew-symmetric matrix for the vector part of the quaternion
    qahat = ca.SX.zeros(3, 3)
    qahat[0, 1] = -q[3]  # -qz
    qahat[0, 2] = q[2]   # qy
    qahat[1, 2] = -q[1]  # -qx
    qahat[1, 0] = q[3]   # qz
    qahat[2, 0] = -q[2]  # -qy
    qahat[2, 1] = q[1]   # qx

    # Step 3: Compute the rotation matrix
    I = ca.SX.eye(3)
    R = I + 2 * (qahat @ qahat) + 2 * q[0] * qahat

    return R




def payload_model(params):
    #model
    model_name = "payload_model"    

    #payload params
    m = params.mass
    g = params.grav
    I_load = params.I                           #intertia
    M_load = m * np.eye((3))                    #mass distribution

    ##frames
    #inertial 
    e1 = ca.vertcat(1.0,0,0)
    e2 = ca.vertcat(0,1,0)
    e3 = ca.vertcat(0,0,1)

    #payload frame 
    L1 = ca.vertcat(1.0,0,0)
    L2 = ca.vertcat(0,1,0)
    L3 = ca.vertcat(0,0,1)

    #define input variables
    f1 = ca.SX.sym("f1")
    f2 = ca.SX.sym("f2")
    f3 = ca.SX.sym("f3")
    F = ca.vertcat(f1, f2, f3)              #force in Inertial frame

    m1 = ca.SX.sym("m1")
    m2 = ca.SX.sym("m2")
    m3 = ca.SX.sym("m3")
    M = ca.vertcat(m1, m2, m3)              #moments in Payload frame

    v1 = ca.SX.sym('v1')
    v2 = ca.SX.sym('v2')
    v3 = ca.SX.sym('v3')
    V = ca.vertcat(v1, v2, v3)              #null space vector 

    W = ca.vertcat(f1, f2, f3, m1, m2, m3, v1, v2, v3)
    
    #state variables - pos, linear vel, quaternions and angular velocities
    #position 
    x_p = ca.SX.sym('x_p')
    y_p = ca.SX.sym('y_p')
    z_p = ca.SX.sym('z_p')
    x_1 = ca.vertcat(x_p, y_p, z_p)
    
    #linear vel
    vx = ca.SX.sym("vx")
    vy = ca.SX.sym("vy")
    vz = ca.SX.sym("vz")   
    vel = ca.vertcat(vx,vy,vz)

    #angles quaternion 
    qw = ca.SX.sym('qw')
    qx = ca.SX.sym('qx')
    qy = ca.SX.sym('qy')
    qz = ca.SX.sym('qz')        
    quat = ca.vertcat(qw,qx, qy,qz)

    #angular velocity
    p = ca.SX.sym('p')
    q = ca.SX.sym('q',)
    r = ca.SX.sym('r')
    omega = ca.vertcat(p,q,r) 

    x = ca.vertcat(x_1, vel, quat, omega)

    ##derivatives
    #position in Inertial frame
    xp_dt = ca.SX.sym('xp_dt')
    yp_dt = ca.SX.sym('yp_dt')
    zp_dt = ca.SX.sym('zp_dt')
    x1_dt = ca.vertcat(xp_dt, yp_dt, zp_dt)
    
    #linear velocity in Inertial frame 
    vx_dt = ca.SX.sym('vx_dt')
    vy_dt = ca.SX.sym('vy_dt')
    vz_dt = ca.SX.sym('vz_dt')
    vel_dt = ca.vertcat(vx_dt, vy_dt, vz_dt)

    ##angles in Inertial frame
    qw_dt = ca.SX.sym('qw_dt')
    qx_dt = ca.SX.sym('qx_dt')
    qy_dt = ca.SX.sym('qy_dt')
    qz_dt = ca.SX.sym('qz_dt')
    quat_dt = ca.vertcat(qw_dt, qx_dt, qy_dt, qz_dt)

    #angular velolcity in Payload frame
    p_dt = ca.SX.sym('p_dt')
    q_dt = ca.SX.sym('q_dt')
    r_dt = ca.SX.sym('r_dt')
    omega_dt = ca.vertcat(p_dt,q_dt,r_dt)
    x_dot = ca.vertcat(x1_dt, vel_dt, quat_dt, omega_dt)

    ##refence input
    
    
    #system dynamics 
    #angular velocity
    K_quat = 2                                                          #this enforces the magnitude 1 constraint for the quaternion
    quaterror = 1 - (qw**2 + qx**2 + qy**2 + qz**2)                     #norm_2(quat) 
    a_matrix = ca.vertcat(  ca.horzcat(0,- p,- q,- r),
               ca.horzcat(p,0,r,-q),
               ca.horzcat(q,-r,0,p),
               ca.horzcat(r,q,-p,0))
    quat_dt = 1/2 *ca.mtimes(a_matrix, quat) + K_quat * ca.mtimes(quaterror, quat)

    #calculate rotation matrix
    #Rwb = CaQuatToRot(quat)
    #Inerttia and other forces     
    cc_forces = ca.cross(omega, ca.mtimes(I_load, omega))               #colaris and centripetel forces 
    f_expl = ca.vertcat(vel,
                        ca.mtimes(ca.inv(M_load) ,(F - m * g * e3)),
                        quat_dt,
                        ca.mtimes(ca.inv(I_load), (M - cc_forces))
                        )
   
 
    model = AcadosModel()                
    model.name = model_name
    f_impl = x_dot - f_expl 
    model.f_impl_expr = f_impl
    model.f_expl_expr = f_expl
    model.x = x
    model.xdot = x_dot
    model.u = W 
    #model.y = cc_forces
    nx = model.x.rows()
    nu = model.u.rows()
    reference_param = ca.SX.sym('references', (nx + nu), 1)
    model.p = reference_param    
    return model

   

if __name__ == "__main__":
    filename = '/home/dhruv/RotorTM/src/rotor_tm_config/config/load_params/triangular_payload.yaml'
    read_params_funcs = read_params.read_params()
    control_params = read_params_funcs.read_payload_params(filename)
    f_expl = payload_model(control_params)
    q_in = np.array([1.0, 0.1,0.2,0.3])
    omg = np.array([1,2,3])
    Mass = np.diag([0.250,0.250,0.250])
    F = [1,1,1]
   




import numpy as np
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


def Payload_ODE(X, U, params):
    #payload params
    m = params.mass
    g = params.grav
    I_load = params.I                           #intertia
    M_load = m * np.eye((3))                    #mass distribution

    #inertial frame 
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
    
    X_next = ca.vertcat(vel,
                        ca.mtimes(np.linalg.inv(M_load) ,(F - m * g * e3)),
                        quat_dt,
                        ca.mtimes(np.linalg.inv(I_load), (M - cc_forces))
                        )
    
    return X_next
    

def temp_fun(init_flag, hx0):
    
    
    return init_flag, hx0 
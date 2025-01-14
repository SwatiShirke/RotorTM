import casadi as ca


def cal_qdt(quat1, omega1):
    p = ca.SX.sym('p')
    q = ca.SX.sym('q',)
    r = ca.SX.sym('r')
    omega = ca.vertcat(p,q,r) 

    
    #angles quaternion 
    qw = ca.SX.sym('qw')
    qx = ca.SX.sym('qx')
    qy = ca.SX.sym('qy')
    qz = ca.SX.sym('qz')        
    quat = ca.vertcat(qw,qx, qy,qz)
    
    a_matrix = ca.vertcat(  ca.horzcat(0,- p,- q,- r),
               ca.horzcat(p,0,r,-q),
               ca.horzcat(q,-r,0,p),
               ca.horzcat(r,q,-p,0)) 
    
    qdt = 1/2 *ca.mtimes(a_matrix, quat)
    f_expr = ca.Function('f_expr', [quat, omega], [qdt])
    f_out = f_expr(quat1, omega1)
    #print(f_out)
    return f_out

        


if __name__ == '__main__': 
    #test cal_qdt   
    q_in = [1.0, 0.1,0.2,0.3]
    o_in = [1,2,3]
    q_dt = cal_qdt(q_in, o_in)
    print(q_dt)



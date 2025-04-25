import numpy as np
from scipy.linalg import expm

def trajectory(t, zi, w_c):
    p, theta, p_d, theta_d, p_dd, p_ddd, p_dddd, theta_dd = ref_circular_trajectory(t, zi, w_c)
    a = np.pi/2
    b = 0.00
    r = np.zeros((3, p_d.shape[1]), dtype=np.double)
    r_d = np.zeros((3, p_d.shape[1]), dtype=np.double)
    r_dd = np.zeros((3, p_d.shape[1]), dtype=np.double)
    r_ddd = np.zeros((3, p_d.shape[1]), dtype=np.double)
    r_dddd = np.zeros((3, p_d.shape[1]), dtype=np.double)

    for k in range(0, p_d.shape[1]):
        w = np.array([a*np.sin(b*t[k]), 0.0, 0.0], dtype=np.double)
        w_d = np.array([b*a*np.cos(b*t[k]), 0.0, 0.0], dtype=np.double)
        w_dd = np.array([-b*b*a*np.sin(b*t[k]), 0.0, 0.0], dtype=np.double)
        w_ddd = np.array([-b*b*b*a*np.cos(b*t[k]), 0.0, 0.0], dtype=np.double)
        w_dddd = np.array([b*b*b*b*a*np.sin(b*t[k]), 0.0, 0.0], dtype=np.double)

        # Aux variables first derivative
        skew_w_d = skew_matrix(w_d)
        skew_w_d_2 = skew_matrix(w_d)@skew_matrix(w_d)
        skew_w_d_3 = skew_matrix(w_d)@skew_matrix(w_d)@skew_matrix(w_d)
        skew_w_d_4 = skew_matrix(w_d)@skew_matrix(w_d)@skew_matrix(w_d)@skew_matrix(w_d)

        # Aux second derivative
        skew_w_dd = skew_matrix(w_dd)
        skew_w_dd_2 = skew_matrix(w_dd)@skew_matrix(w_dd)

        # Aux third derivative
        skew_w_ddd = skew_matrix(w_ddd)

        # Aux fourth derivative
        skew_w_dddd = skew_matrix(w_dddd)

        # New Desired reference
        r[:, k] = expm(skew_matrix(w))@p[:, k]
        r_d[:, k] = expm(skew_matrix(w))@(p_d[:, k] + skew_w_d@p[:, k])
        r_dd[:, k] = expm(skew_matrix(w))@(skew_w_d_2@p[:, k] + 2*skew_w_d@p_d[:, k] + p_dd[:, k] + skew_w_dd@p[:, k])
        r_ddd[:, k] = expm(skew_matrix(w))@(p_ddd[:, k] + skew_w_ddd@p[:, k] + 3*skew_w_dd@p_d[:, k] + 3*skew_w_d@p_dd[:, k] + skew_w_d_3@p[:, k] + 3*skew_w_d_2@p_d[:, k] + 3 * skew_w_d@skew_w_dd@p[:, k])
        r_dddd[:, k] = expm(skew_matrix(w))@(p_dddd[:, k] + skew_w_dddd@p[:, k] + 4 * skew_w_ddd@p_d[:, k] + 6*skew_w_dd@p_dd[:, k] + 4 * skew_w_d@p_ddd[:, k] + skew_w_d_4@p[:, k] + 3*skew_w_dd_2@p[:, k] + 4*skew_w_d_3@p_d[:, k] + 6*skew_w_d_2@p_dd[:, k] + 6*skew_w_d_2@skew_w_dd@p[:, k] + 4*skew_w_d@skew_w_ddd@p[:, k] + 12*skew_w_d@skew_w_dd@p_d[:, k])

    x0 = 0 * np.zeros((t.shape[0]))
    y0 = 0 * np.zeros((t.shape[0]))
    z0 = 6 * np.ones((t.shape[0]))

    h0 = np.vstack((x0, y0, z0))
    r = r + h0
    return r, r_d, r_dd, r_ddd, r_dddd, theta, theta_d, theta_dd

def skew_matrix(x):
    a1 = x[0]
    a2 = x[1]
    a3 = x[2]
    A = np.array([[0.0, -a3, a2], [a3, 0.0, -a1], [-a2, a1, 0.0]], dtype=np.double)
    return A

def ref_circular_trajectory(t, p, w_c):
    # Compute the desired Trajecotry of the system
    # COmpute Desired Positions
    xd = p * np.cos(w_c*t)
    yd = p * np.sin(w_c*t)
    zd = 0 * np.zeros((t.shape[0]))

    # Compute velocities
    xd_p = - p * w_c * np.sin(w_c * t)
    yd_p =   p * w_c * np.cos(w_c * t)
    zd_p = 0 * np.zeros((t.shape[0]))

    # Compute acceleration
    xd_pp = - p * w_c * w_c * np.cos(w_c * t)
    yd_pp = - p * w_c * w_c * np.sin(w_c * t) 
    zd_pp = 0 * np.zeros((t.shape[0]))

    # Compute jerk
    xd_ppp =  p * w_c * w_c * w_c * np.sin(w_c * t)
    yd_ppp = - p * w_c * w_c * w_c * np.cos(w_c * t) 
    zd_ppp = 0 * np.zeros((t.shape[0]))

    # Compute snap
    xd_pppp = p * w_c * w_c * w_c * w_c * np.cos(w_c * t)
    yd_pppp = p * w_c * w_c * w_c * w_c * np.sin(w_c * t)
    zd_pppp = 0 * np.zeros((t.shape[0]))

    # Compute angular displacement
    theta = 0 * np.zeros((t.shape[0]))

    # Compute angular velocity
    theta_p = 0 * np.zeros((t.shape[0]))
    #theta = np.arctan2(yd_p, xd_p)
    #theta = theta

    # Compute angular velocity
    #theta_p = (1. / ((yd_p / xd_p) ** 2 + 1)) * ((yd_pp * xd_p - yd_p * xd_pp) / xd_p ** 2)
    #theta_p[0] = 0.0

    theta_pp = 0 * np.zeros((theta.shape[0]))

    hd = np.vstack((xd, yd, zd))
    hd_p = np.vstack((xd_p, yd_p, zd_p))
    hd_pp = np.vstack((xd_pp, yd_pp, zd_pp))
    hd_ppp = np.vstack((xd_ppp, yd_ppp, zd_ppp))
    hd_pppp = np.vstack((xd_pppp, yd_pppp, zd_pppp))
    return hd, theta, hd_p, theta_p, hd_pp, hd_ppp, hd_pppp, theta_pp
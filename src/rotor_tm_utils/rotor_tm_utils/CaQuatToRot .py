import casadi as ca

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
    R = I + 2 * ca.mtimes(qahat, qahat) + 2 * q[0] * qahat

    return R



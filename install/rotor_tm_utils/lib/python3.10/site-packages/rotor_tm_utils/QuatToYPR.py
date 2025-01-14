import casadi as ca

def QuatToYPR(quat):
    """
    Convert a quaternion (w, x, y, z) to yaw, pitch, and roll (in radians) using CasADi symbolic expressions.

    Args:
        quat (list or CasADi array): Quaternion [w, x, y, z].

    Returns:
        tuple: (yaw, pitch, roll) in radians as CasADi symbolic expressions.
    """
    w = quat[0]
    x = quat[1]
    y = quat[2]
    z = quat[3]

    # Yaw (Z-axis rotation)
    yaw = ca.atan2(2 * (w * z + x * y), 1 - 2 * (y**2 + z**2))

    # Pitch (Y-axis rotation)
    sinp = 2 * (w * y - z * x)
    
    # Abs value computation with CasADi (using sqrt for abs value)
    abs_value = ca.sqrt(sinp**2)

    # Conditional logic in CasADi
    pitch = ca.if_else(abs_value >= 1, ca.sign(sinp) * ca.pi / 2, ca.asin(sinp))

    # Roll (X-axis rotation)
    roll = ca.atan2(2 * (w * x + y * z), 1 - 2 * (x**2 + y**2))

    return yaw, pitch, roll
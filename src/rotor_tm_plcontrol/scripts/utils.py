import yaml
import numpy as np
import casadi as ca

def read_yaml(filename):
    with open (filename,'r') as file:
        data = yaml.safe_load(file)
    #print(data)
    return data



def QuatToRot(quat):
    """
    Convert a quaternion [w, x, y, z] to a 3x3 rotation matrix.

    Parameters:
        quat (list or array): Quaternion as [w, x, y, z]

    Returns:
        numpy.ndarray: 3x3 rotation matrix
    """
    w = quat[0]
    x = quat[1]
    y = quat[2]
    z = quat[3]
    #[w, x, y, z ]= quat[0]
    row1 = ca.horzcat(1 - 2*y**2 - 2*z**2, 2*x*y - 2*z*w, 2*x*z + 2*y*w)
    row2 = ca.horzcat(2*x*y + 2*z*w, 1 - 2*x**2 - 2*z**2, 2*y*z - 2*x*w)
    row3 = ca.horzcat(2*x*z - 2*y*w, 2*y*z + 2*x*w, 1 - 2*x**2 - 2*y**2)
    
    # Concatenate rows vertically to form the rotation matrix
    R = ca.vertcat(row1, row2, row3)

    return R

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

if __name__ == '__main__':
    # Example usage
    quat = [0.7071, 0.7071, 0, 0]  # Quaternion (w, x, y, z)
    rotation_matrix = QuatToRot(quat)
    print("Rotation Matrix:\n", rotation_matrix)

    # Example usage
    quaternion = [0.7071, 0.7071, 0, 0]  # Example quaternion
    yaw, pitch, roll = QuatToYPR(quaternion)
    print(f"Yaw: {yaw:.4f}, Pitch: {pitch:.4f}, Roll: {roll:.4f} (radians)")




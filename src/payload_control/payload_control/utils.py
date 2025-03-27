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

# Transfer a 3 dimensional vector to a matrix
# For a numpy array the expexted shape is (3,) or (3,1)
def vec2asym(vec):
  if  (type(vec) is np.ndarray):
    # If it is a 1d-array
    if len(vec.shape) == 1:
      # Store row size and column=0
      row = vec.shape[0]
      col = 0
    # If it is a 2d-array
    elif len(vec.shape) == 2:
      # Store the row size and column size(shoud be 1 for a vector)
      row = vec.shape[0]
      col = vec.shape[1]
  elif type(vec) is list:
      # If it is a list
      # Store the row size as length of the list adn column=0      
      row = len(vec)
      col = 0
  # Input should be a numpy array or a list
  else:
    raise Exception("The vector type not list or numpy array")
  if row == 3: 
    # If 1-d array
    if col == 0:
      mat = np.array([[0,-vec[2],vec[1]],
                      [vec[2],0,-vec[0]],
                      [-vec[1],vec[0],0]])
    # If 2-d array with col=1
    elif col == 1:
      mat = np.array([[0,-vec[2][0],vec[1][0]],
                      [vec[2][0],0,-vec[0][0]],
                      [-vec[1][0],vec[0][0],0]])
    # Column size should be 1 or less
    else:
      raise Exception("Input is a matrix. Expected a vector")
  # Row size should be 3
  else:
    raise Exception("The vector shape is not 3")
  
  # Return the skew symmetric matrix
  return mat


# Include the header
std_msgs/Header header

# Scalar fields
float64 thrust
float64 roll
float64 pitch
float64 yaw

# Vector fields from geometry_msgs
geometry_msgs/Vector3 angular_velocity
geometry_msgs/Quaternion quaternion

# Use float64[] for arrays
float64[3] k_r  # k_r as an array of float64
float64[3] k_om  # k_om as an array of float64


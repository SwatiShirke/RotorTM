# Include the header
std_msgs/Header header

# Vector3 from geometry_msgs
geometry_msgs/Vector3 force
geometry_msgs/Quaternion orientation
geometry_msgs/Vector3 angular_velocity

# Use float64[] for arrays in ROS2
float64[3] k_r
float64[3] k_om


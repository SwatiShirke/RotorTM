import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/swati/Quad_DR/ros2_ws/install/rotor_tm_utils'

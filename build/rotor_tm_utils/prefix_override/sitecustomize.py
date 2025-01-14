import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/swati/Quad_DR/RotorTM/install/rotor_tm_utils'

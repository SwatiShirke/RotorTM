#!/usr/bin/python3
#from MpcControl import *
import sys
import numpy as np
from pathlib import Path
from rotor_tm_utils import read_params
import rotor_tm_sim.simulation_base as sm
import rclpy


def main(args = None):
  rclpy.init(args = args)
  
  print(sys.argv[1])
  payload_params_path = sys.argv[1]
  uav_params_path = sys.argv[2]
  mechanism_params_path = sys.argv[3]
  payload_control_gain_path = sys.argv[4]
  uav_control_gain_path = sys.argv[5]

  ##**Case 1
  # payload_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/load_params/pointmass_payload.yaml"
  # uav_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/uav_params/"
  # mechanism_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/attach_mechanism/cable/1_robot_point_mass_0-5m.yaml"
  # payload_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/pointmass_cable_gains.yaml"
  # uav_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/"
  
  ##case 2
  # payload_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/load_params/triangular_payload.yaml"
  # uav_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/uav_params/"
  # mechanism_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/attach_mechanism/cable/3_robots_triangular_payload_1m_bullnose_dragonfly.yaml"
  # payload_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_rigidlink_gains.yam"
  # uav_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/"
  
  # payload_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/load_params/triangular_payload.yaml"
  # uav_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/uav_params/"
  # mechanism_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/attach_mechanism/rigid_link/3_robots_triangular_payload.yaml"
  # payload_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_cable_gains.yaml"
  # uav_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/"
  
  # payload_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/load_params/fedex_box_payload.yaml"
  # uav_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/uav_params/"
  # mechanism_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/attach_mechanism/cable/4_robots_fedex_box_0_5m.yaml"
  # payload_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_cable_gains.yaml"
  # uav_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/"
 
  # payload_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/load_params/fedex_box_payload.yaml"
  # uav_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/uav_params/"
  # mechanism_params_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/attach_mechanism/cable/6_robots_fedex_box_0_5m.yaml"
  # payload_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_cable_gains.yaml"
  # uav_control_gain_path = "/home/swati/Quad_DR/ros2_ws/src/rotor_tm_config/config/control_params/"

 
  read_params_funcs = read_params.read_params()
  pl_params, quad_params = read_params_funcs.system_setup(payload_params_path,uav_params_path,mechanism_params_path,payload_control_gain_path, uav_control_gain_path)
   
  rotortm_simulation_base = sm.simulation_base(pl_params,quad_params)
  rclpy.spin(rotortm_simulation_base)
  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()



  
   
    

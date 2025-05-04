from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.conditions import IfCondition
#from launch.frontend import Component
import os

def generate_launch_description():
    controller_launches = []
    pkg_path = get_package_share_directory("rotor_tm_config") 
    sim_pkg_path = get_package_share_directory("rotor_tm_sim")

    return LaunchDescription([
        DeclareLaunchArgument(
            'payload_params_path',
            #default_value=os.path.join(pkg_path , 'config', 'load_params/pointmass_payload.yaml'),
            default_value=os.path.join(pkg_path , 'config', 'load_params/triangular_payload.yaml'),
            description='Path to the payload parameters file'
        ),
        DeclareLaunchArgument(
            'uav_params_path',
            default_value=os.path.join(pkg_path , 'config', 'uav_params/'),
            description='Path to the UAV parameters file'
        ),
        DeclareLaunchArgument(
            'mechanism_params_path',
            #default_value=os.path.join(pkg_path , 'config', 'attach_mechanism/cable/1_robot_point_mass_0-5m.yaml'),
            default_value=os.path.join(pkg_path , 'config', 'attach_mechanism/cable/3_robots_triangular_payload_0-5m.yaml'),
            description='Path to the mechanism parameters file'
        ),
        DeclareLaunchArgument(
            'payload_control_gain_path',
            #default_value=os.path.join(pkg_path , 'config', 'control_params/pointmass_cable_gains.yaml'), 
            default_value=os.path.join(pkg_path , 'config', 'control_params/triangular_payload_cooperative_cable_gains.yaml'),
            #description='Path to the payload control gains file'
        ),
        DeclareLaunchArgument(
            'uav_control_gain_path',
            default_value=os.path.join(pkg_path , 'config', 'control_params/'),
            description='Path to the UAV control gains file'
        ),
        DeclareLaunchArgument(
            'number_of_robots',
            default_value='3',
            description='Number of UAVs'
        ),
        
        #Start simulation and trajectory nodes 
        Node(
            package='rotor_tm_sim',
            executable='sim_node',
            name='sim_node',
            output='screen',
            arguments=[
                LaunchConfiguration('payload_params_path'),
                LaunchConfiguration('uav_params_path'),
                LaunchConfiguration('mechanism_params_path'),
                LaunchConfiguration('payload_control_gain_path'),
                LaunchConfiguration('uav_control_gain_path')
            ],
        ),
        
        Node(
            package='rotor_tm_traj',
            executable='traj_node',
            name='traj',
            output='screen',
        ),
        
        # # # Recursively launch controller         
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(sim_pkg_path , 'launch', 'controller_launcher.py')),
            condition=IfCondition(PythonExpression([ LaunchConfiguration('number_of_robots'), ' > 0'])),
            launch_arguments={
                'uav_params_path': LaunchConfiguration('uav_params_path'),
                'payload_params_path': LaunchConfiguration('payload_params_path'),
                'mechanism_params_path': LaunchConfiguration('mechanism_params_path'),
                'payload_control_gain_path': LaunchConfiguration('payload_control_gain_path'),
                'uav_control_gain_path': LaunchConfiguration('uav_control_gain_path'),
                'number_of_robots': LaunchConfiguration('number_of_robots'),
                'nr': LaunchConfiguration('number_of_robots')
            }.items()
        ),
                
        # Include RViz launch file
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(sim_pkg_path , 'launch', 'rviz.py')),

            ),
    ])

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.conditions import IfCondition
#from launch.frontend import Component
import os
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode
import yaml

def read_config_yaml(file_path):
    with open(file_path,"r") as file:
        params = yaml.safe_load(file)
        config = params["config_paths"]  
        return config

def generate_launch_description():
    controller_launches = []
    pkg_path = get_package_share_directory("rotor_tm_config") 
    sim_pkg_path = get_package_share_directory("rotor_tm_sim")
    group_ns = "nmpc_control"
    c_node = ComposableNode(package="rotor_tm_plcontrol",
                                     namespace=group_ns,
                                     name="nmpc_control_nodelet",
                                     remappings=[                                       
                                     ],
                                     plugin="nmpc_control_nodelet::NMPCControlNodelet",
                                     parameters=[])
    
    #read all config file's path from main_config.yaml
    main_config_path = os.path.join(pkg_path , 'config', 'main_config.yaml')
    config = read_config_yaml(main_config_path)
    payload_params_path = config["payload_params_path"]
    uav_params_path = config["uav_params_path"]
    mechanism_params_path = config["mechanism_params_path"]
    payload_control_gain_path = config["payload_control_gain_path"]
    uav_control_gain_path = config["uav_control_gain_path"]
    nmpc_filename = config["nmpc_filename"]

    return LaunchDescription([
        DeclareLaunchArgument(
            'payload_params_path',            
            default_value=os.path.join(pkg_path , 'config', payload_params_path),
            description='Path to the payload parameters file'
        ),
        DeclareLaunchArgument(
            'uav_params_path',
            default_value=os.path.join(pkg_path , 'config', uav_params_path),
            description='Path to the UAV parameters file'
        ),
        DeclareLaunchArgument(
            'mechanism_params_path',            
            default_value=os.path.join(pkg_path , 'config', mechanism_params_path),
            description='Path to the mechanism parameters file'
        ),
        DeclareLaunchArgument(
            'payload_control_gain_path', 
            default_value=os.path.join(pkg_path , 'config', payload_control_gain_path),
            description='Path to the payload control gains file'
        ),
        DeclareLaunchArgument(
            'uav_control_gain_path',
            default_value=os.path.join(pkg_path , 'config', uav_control_gain_path),
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
        ComposableNodeContainer(name='container_1',
                                namespace=group_ns,
                                package='rclcpp_components',
                                executable='component_container',
                                composable_node_descriptions=[
                                  c_node
                                ],
                                output='screen',
                                emulate_tty=True),
           
        # Include RViz launch file
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(sim_pkg_path , 'launch', 'rviz.py')),

            ),
    ])

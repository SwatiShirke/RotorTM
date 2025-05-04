from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
import os 

def generate_launch_description():
    # Declare paths as launch arguments
    pkg_path = get_package_share_directory("rotor_tm_config") 
    sim_pkg_path = get_package_share_directory("rotor_tm_sim")

    return LaunchDescription([
         DeclareLaunchArgument(
            'payload_params_path',
            default_value=os.path.join(pkg_path , 'config', 'load_params/pointmass_payload.yaml'),
            #default_value=os.path.join(pkg_path , 'config', 'load_params/triangular_payload.yaml'),
            description='Path to the payload parameters file'
        ),
        DeclareLaunchArgument(
            'uav_params_path',
            default_value=os.path.join(pkg_path , 'config', 'uav_params/'),
            description='Path to the UAV parameters file'
        ),
        DeclareLaunchArgument(
            'mechanism_params_path',
            default_value=os.path.join(pkg_path , 'config', 'attach_mechanism/cable/1_robot_point_mass_0-5m.yaml'),
            #default_value=os.path.join(pkg_path , 'config', 'attach_mechanism/cable/3_robots_triangular_payload_0-5m.yaml'),
            description='Path to the mechanism parameters file'
        ),
        DeclareLaunchArgument(
            'payload_control_gain_path',
            default_value=os.path.join(pkg_path , 'config', 'control_params/pointmass_cable_gains.yaml'), 
            #default_value=os.path.join(pkg_path , 'config', 'control_params/triangular_payload_cooperative_cable_gains.yaml'),
            description='Path to the payload control gains file'
        ),
        DeclareLaunchArgument(
            'uav_control_gain_path',
            default_value=os.path.join(pkg_path , 'config', 'control_params/'),
            description='Path to the UAV control gains file'
        ),
        DeclareLaunchArgument(
            'number_of_robots',
            default_value='1',
            description='Number of UAVs'
        ),

        DeclareLaunchArgument(
            'rviz_launch_file_path',
            default_value=os.path.join(sim_pkg_path , 'launch', 'rviz.py'),
            description='Rviz2 file'
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

        # # Include the RViz launch file
        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource(LaunchConfiguration('rviz_launch_file_path'))
        # )
        
        ])

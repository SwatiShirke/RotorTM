from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Declare paths as launch arguments
    uav_params_path = DeclareLaunchArgument(
        'uav_params_path',
        default_value=PathJoinSubstitution([
            FindPackageShare('rotor_tm_config'), 'config', 'uav_params'
        ])
    )
    
    payload_params_path = DeclareLaunchArgument(
        'payload_params_path',
        default_value=PathJoinSubstitution([
            FindPackageShare('rotor_tm_config'), 'config', 'load_params', 'fedex_box_payload.yaml'
        ])
    )
    
    mechanism_params_path = DeclareLaunchArgument(
        'mechanism_params_path',
        default_value=PathJoinSubstitution([
            FindPackageShare('rotor_tm_config'), 'config', 'attach_mechanism', 'cable', 
            '3_robots_triangular_payload_1m_different_robots_dynamics.yaml'
        ])
    )
    
    payload_control_gain_path = DeclareLaunchArgument(
        'payload_control_gain_path',
        default_value=PathJoinSubstitution([
            FindPackageShare('rotor_tm_config'), 'config', 'control_params', 
            'triangular_payload_cooperative_cable_gains.yaml'
        ])
    )
    
    uav_control_gain_path = DeclareLaunchArgument(
        'uav_control_gain_path',
        default_value=PathJoinSubstitution([
            FindPackageShare('rotor_tm_config'), 'config', 'control_params'
        ])
    )
    
    rviz_launch_file_path = DeclareLaunchArgument(
        'rviz_launch_file_path',
        default_value=PathJoinSubstitution([
            FindPackageShare('rotor_tm'), 'launch', 'rviz.launch.py'
        ])
    )

    # Simulation node
    sim_node = Node(
        package='rotor_tm',
        executable='runsim.py',
        name='sim',
        output='screen',
        arguments=[
            LaunchConfiguration('payload_params_path'),
            LaunchConfiguration('uav_params_path'),
            LaunchConfiguration('mechanism_params_path'),
            LaunchConfiguration('payload_control_gain_path'),
            LaunchConfiguration('uav_control_gain_path')
        ]
    )

    # Include the RViz launch file
    rviz_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(LaunchConfiguration('rviz_launch_file_path'))
    )

    # Launch description
    return LaunchDescription([
        uav_params_path,
        payload_params_path,
        mechanism_params_path,
        payload_control_gain_path,
        uav_control_gain_path,
        rviz_launch_file_path,
        sim_node,
        rviz_launch
    ])

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Define launch arguments
    a_arg = DeclareLaunchArgument('a', default_value='0')
    b_arg = DeclareLaunchArgument('b', default_value='1')
    c_arg = DeclareLaunchArgument('c', default_value='2')
    single_node_arg = DeclareLaunchArgument('single_node', default_value='1')
    
    # Nodes
    sim_node = Node(
        package='rotor_tm',
        executable='runsim.py',
        name='sim',
        output='screen'
    )

    traj_node = Node(
        package='rotor_tm_traj',
        executable='traj_node.py',
        name='traj',
        output='screen'
    )

    controller_node = Node(
        package='rotor_tm_control',
        executable='controller_node.py',
        name='controller',
        output='screen',
        arguments=[LaunchConfiguration('a'), LaunchConfiguration('single_node')]
    )

    # Include files
    rotortm_robot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([FindPackageShare('rotor_tm'), '/launch/rotortm_robot.launch.py']),
        launch_arguments={'mav_name': 'dragonfly1'}.items()
    )

    rviz_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([FindPackageShare('rotor_tm'), '/launch/rviz.launch.py'])
    )

    # Launch description
    return LaunchDescription([
        a_arg,
        b_arg,
        c_arg,
        single_node_arg,
        sim_node,
        traj_node,
        controller_node,
        # Uncomment the line below to include `rotortm_robot.launch.py`
        # rotortm_robot_launch,
        rviz_launch
    ])

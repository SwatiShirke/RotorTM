from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Define the path to the RViz configuration file
    rviz_config_path = PathJoinSubstitution([
        FindPackageShare('rotor_tm_sim'), 'launch', 'rviz_config_ukf_vio.rviz2'
    ])

    # RViz Node
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz',
        arguments=['-d', rviz_config_path],
        output='screen'
    )

    # Launch description
    return LaunchDescription([
        rviz_node
    ])

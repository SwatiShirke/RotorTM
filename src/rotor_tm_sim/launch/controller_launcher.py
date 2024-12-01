from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch_ros.descriptions import ComposableNode
from ament_index_python.packages import get_package_share_directory
#from launch_ros.events import EventHandler
from launch.conditions import IfCondition
import os

def generate_launch_description():
    sim_pkg_path = get_package_share_directory("rotor_tm_sim")
    #number_of_robots = int(launch_configurations['number_of_robots'])
    #nr = int(launch_configurations['nr'])

    return LaunchDescription([
        DeclareLaunchArgument('uav_params_path'),
        DeclareLaunchArgument('payload_params_path'),
        DeclareLaunchArgument('mechanism_params_path'),
        DeclareLaunchArgument('payload_control_gain_path'),
        DeclareLaunchArgument('uav_control_gain_path'),
        DeclareLaunchArgument('number_of_robots'),
        DeclareLaunchArgument('nr'),
        DeclareLaunchArgument('single_node', default_value='0'),
        DeclareLaunchArgument('index', default_value = '0'),

        
        Node(
            package='rotor_tm_control',
            executable='controller_node',
            #name= PythonExpression([f"'controller_' + str(int({LaunchConfiguration('number_of_robots')}) - int({LaunchConfiguration('nr')}) + 1)"]),
            #name = f"controller_{int(str(LaunchConfiguration('number_of_robots'))) - int(str(LaunchConfiguration('nr'))) + 1}",
            #name=PythonExpression(["'controller_' + str(int(", LaunchConfiguration('number_of_robots'), ") - int(",LaunchConfiguration('nr'),") + 1)"]),
            name=PythonExpression(["'controller_' + str(", LaunchConfiguration('nr'), ")"]),
            output='screen',
            
            arguments=[
                LaunchConfiguration('index'),
                LaunchConfiguration('single_node'),
                LaunchConfiguration('payload_params_path'),
                LaunchConfiguration('uav_params_path'),
                LaunchConfiguration('mechanism_params_path'),
                LaunchConfiguration('payload_control_gain_path'),
                LaunchConfiguration('uav_control_gain_path')
            ],
            
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(sim_pkg_path , 'launch', 'controller_launcher.py')),
            condition=IfCondition(PythonExpression([LaunchConfiguration('nr'), '-1' ,   '> 0'])),
            launch_arguments={
                'uav_params_path': LaunchConfiguration('uav_params_path'),
                'payload_params_path': LaunchConfiguration('payload_params_path'),
                'mechanism_params_path': LaunchConfiguration('mechanism_params_path'),
                'payload_control_gain_path': LaunchConfiguration('payload_control_gain_path'),
                'uav_control_gain_path': LaunchConfiguration('uav_control_gain_path'),
                'number_of_robots': LaunchConfiguration('number_of_robots'),
                'nr': PythonExpression([LaunchConfiguration('nr'), '-','1']),
                'index': PythonExpression([ LaunchConfiguration('number_of_robots'),  '-',  LaunchConfiguration('nr')  ])
                
            }.items()
        ),
    ])

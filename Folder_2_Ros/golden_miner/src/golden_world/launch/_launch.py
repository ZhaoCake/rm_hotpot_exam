# a launch file for the golden world project
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():

    return LaunchDescription([
        Node(package='golden_world',
             executable='golden_world_node',
             name='golden_world_node',
             output='screen',
             parameters=[{
                 'mineral_count': 10
             }]),
        Node(package='golden_world',
             executable='miner_node',
             name='miner_node',
             output='screen'),
        #    Node(
        #    package='rviz2',
        #    executable='rviz2',
        #    name='rviz',
        #    output='screen',
        #    arguments=['-d', './ros_exam.rviz'])
    ])

# a launch file for the golden world project
import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # 加入路径
    rviz_config_dir = os.path.join(get_package_share_directory('golden_world'), 'config', 'ros_exam.rviz')
    para_dir = os.path.join(get_package_share_directory('golden_world'), 'config', 'config.yaml')
    return LaunchDescription([
        Node(package='golden_world',
             executable='golden_world_node',
             name='golden_world_node',
             output='screen',
             parameters=[para_dir]),
        Node(package='golden_world',
             executable='miner_node',
             name='miner_node',
             output='screen'),
        Node(
           package='rviz2',
           executable='rviz2',
           name='rviz',
           output='screen',
           arguments=['-d', rviz_config_dir])
    ])

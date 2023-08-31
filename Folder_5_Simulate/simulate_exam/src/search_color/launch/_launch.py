import os.path
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node
from launch.substitutions import TextSubstitution, LaunchConfiguration
from launch.actions import DeclareLaunchArgument


def generate_launch_description():
    color_launch_arg = DeclareLaunchArgument(
        "color",
        default_value=TextSubstitution(text='blue'),
        description="The color to search for",
    )
    return LaunchDescription([
        color_launch_arg,
        # 启动ign
        ExecuteProcess(
            cmd=[
                "ign gazebo",
                "./src/search_color/src/exam_world.sdf",
            ],
            output="screen",
            shell=True,
        ),
        # ros与ign的桥接节点
        Node(
            package="ros_ign_bridge",
            executable="parameter_bridge",
            name="message_bridge",
            output="screen",
            arguments=["/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist"],
        ),
        # 图传
        Node(
            package="ros_ign_image",
            executable="image_bridge",
            arguments=[
                "camera",
            ],
            output="screen",
            name="camera",
        ),
        Node(
            package="search_color",
            executable="search_color",
            name="search_color",
            output="screen",
            # 传递参数
            parameters=[{
                "color": LaunchConfiguration("color")
            }])
    ])

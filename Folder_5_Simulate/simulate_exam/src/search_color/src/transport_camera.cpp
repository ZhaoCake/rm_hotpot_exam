#include <ignition/transport/Node.hh>  // IGN Transport头文件
#include <sensor_msgs/msg/image.hpp>   // ROS2图像消息头文件
#include <rclcpp/rclcpp.hpp>           // ROS2 C++库头文件

// 回调函数，用于处理接收到的IGN相机图像消息
void imageCallback(const ignition::msgs::Image& ignImage)
{
  // 创建ROS2图像消息对象
  sensor_msgs::msg::Image rosImage;
  // 将IGN相机图像消息转换为ROS2图像消息
  rosImage.data = ignImage.data();
  // 发布ROS2图像消息
  imagePublisher->publish(rosImage);
}

int main(int argc, char** argv)
{
  // 初始化ROS2节点
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("ign_to_ros2_node");

  // 创建IGN Transport节点
  ignition::transport::Node ignNode;

  // 订阅IGN相机话题
  ignition::transport::SubscriberPtr sub =
    ignNode.Subscribe("camera", imageCallback);

  // 创建ROS2图像发布器
  // 假设你要将图像发布到ROS2话题/camera/image
  auto imagePublisher = node->create_publisher<sensor_msgs::msg::Image>("camera", 10);

  // 进入ROS2事件循环
  rclcpp::spin(node);

  // 清理资源
  rclcpp::shutdown();
  
  return 0;
}
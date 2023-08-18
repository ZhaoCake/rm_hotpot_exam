#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/msg/point_stamped.hpp>

// 我翻了api文档，这个头文件里的东西我也没发现哪个用到了，但没有就是通不过编译
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp> 

class PointExam : public rclcpp::Node
{
public:
  PointExam() : Node("coordinate_transform_node") {
    // 创建 tf2_ros::Buffer 和 tf2_ros::TransformListener 对象， 用于坐标系转换
    exam_Buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    exam_Listener_ = std::make_shared<tf2_ros::TransformListener>(*exam_Buffer_, this);
    // 创建定时器，每隔 1 秒执行一次 transformCoordinates() 函数
    timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&PointExam::transformCoordinates, this));
  }

private:
    // 定时器回调函数，用于坐标系转换
  void transformCoordinates() {
    // 创建一个 PointStamped 对象，表示在 camera_optical_link 坐标系下的点
    geometry_msgs::msg::PointStamped point_camera_optical_link;
    point_camera_optical_link.header.frame_id = "camera_optical_link";
    point_camera_optical_link.point.x = 3;
    point_camera_optical_link.point.y = 4;
    point_camera_optical_link.point.z = 5;
    // 将点从 camera_optical_link 坐标系转换到 gimbal_odom 坐标系
    try {
      // 发布到camera_optical_link坐标系下的点
      RCLCPP_INFO(this->get_logger(), "发布到camera_optical_link坐标系下的点: (%f, %f, %f)",
                  point_camera_optical_link.point.x,
                  point_camera_optical_link.point.y,
                  point_camera_optical_link.point.z);
      // 调用 transform() 函数进行坐标系转换，返回转换后的点在 gimbal_odom 坐标系下的坐标
      geometry_msgs::msg::PointStamped transformed_point_gimbal_odom = exam_Buffer_->transform(point_camera_optical_link, "gimbal_odom");

      // 打印转换后的点在 gimbal_odom 坐标系下的坐标
      RCLCPP_INFO(this->get_logger(), "从camera_optical_link转换到gimbal_odom的坐标: (%f, %f, %f)",
                  transformed_point_gimbal_odom.point.x,
                  transformed_point_gimbal_odom.point.y,
                  transformed_point_gimbal_odom.point.z);

      // 再次将点从 gimbal_odom 坐标系转换回 camera_optical_link 坐标系
      geometry_msgs::msg::PointStamped transformed_point_camera_optical_link = exam_Buffer_->transform(transformed_point_gimbal_odom, "camera_optical_link");

      // 打印转换回的点在 camera_optical_link 坐标系下的坐标
      RCLCPP_INFO(this->get_logger(), "从gimbal转换到camera_optical_link的坐标: (%f, %f, %f)",
                  transformed_point_camera_optical_link.point.x,
                  transformed_point_camera_optical_link.point.y,
                  transformed_point_camera_optical_link.point.z);

      // 比较转换前后的点是否相等
      // 先将点的坐标转化为4位小数的浮点数，否则会因为类型不同而即使在数值上相等，也会被认为不相等
      // 四舍五入
        auto point_x = round(point_camera_optical_link.point.x * 10000) / 10000.0;
        auto point_y = round(point_camera_optical_link.point.y * 10000) / 10000.0;
        auto point_z = round(point_camera_optical_link.point.z * 10000) / 10000.0;
        auto transformed_x = round(transformed_point_camera_optical_link.point.x * 10000) / 10000.0;
        auto transformed_y = round(transformed_point_camera_optical_link.point.y * 10000) / 10000.0;
        auto transformed_z = round(transformed_point_camera_optical_link.point.z * 10000) / 10000.0;
        if (
            point_x == transformed_x &&
            point_y == transformed_y &&
            point_z == transformed_z
            ) {
            RCLCPP_INFO(this->get_logger(), "转换前后的点相等");
        } else {
            RCLCPP_INFO(this->get_logger(), "转换前后的点不相等");
            // 转换前后的点
            RCLCPP_INFO(this->get_logger(), "转换前的点: (%f, %f, %f)",
                        point_x, point_y, point_z);
            RCLCPP_INFO(this->get_logger(), "转换后的点: (%f, %f, %f)",
                        transformed_x, transformed_y, transformed_z);
        }
    } catch (tf2::TransformException& ex) {
      // 处理转换异常
      RCLCPP_ERROR(this->get_logger(), "Transform exception: %s", ex.what());
    }
  }

  std::shared_ptr<tf2_ros::Buffer> exam_Buffer_;
  std::shared_ptr<tf2_ros::TransformListener> exam_Listener_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PointExam>());
  rclcpp::shutdown();
  return 0;
}
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"

class HeroListener: public rclcpp::Node {
public:
    HeroListener(): Node("hero_listener") {
        hero_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
        hero_listener_ = std::make_shared<tf2_ros::TransformListener>(*hero_buffer_, this);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&HeroListener::timer_callback, this));
    }

private:
    void timer_callback() {
		try
		{
			auto ts = hero_buffer_ -> lookupTransform("camera_optical_link", "gimbal_odom", tf2::TimePointZero);
			RCLCPP_INFO(this->get_logger(), "Transform from camera_optical_link to gimbal_odom available");
			RCLCPP_INFO(this->get_logger(), "父坐标系：%s, 子坐标系：%s", ts.header.frame_id.c_str(), ts.child_frame_id.c_str());
			RCLCPP_INFO(this->get_logger(), "偏移量: (%f, %f, %f)", ts.transform.translation.x, ts.transform.translation.y, ts.transform.translation.z);
		}
		catch(const std::exception& e)
		{
			RCLCPP_INFO(this->get_logger(), "No transform between camera_optical_link and gimbal_odom");
		}		
    }
    std::unique_ptr<tf2_ros::Buffer> hero_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> hero_listener_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<HeroListener>());
    rclcpp::shutdown();
    return 0;
}

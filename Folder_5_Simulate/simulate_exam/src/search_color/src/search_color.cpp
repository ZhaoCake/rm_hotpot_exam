// 完整观看录播时间：2023年8月17日。
// 和截屏里面的时间不一样，因为我头一次只看到文字要记录时间，第二天再看的时候听到要”留影“，声音有些不清楚，我不肯定确实说的是留影。
#include <opencv2/opencv.hpp>
#include <rclcpp/rclcpp.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/msg/image.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <sensor_msgs/image_encodings.hpp>
#include <chrono>
#include <string>
#include <memory>

class SearchColor : public rclcpp::Node {
public:
	SearchColor() : Node("search_color") {
        // 声明一个带检测颜色的参数
        this->declare_parameter("color", "blue");
		// 读取camera画面
		subscrption_ = this->create_subscription<sensor_msgs::msg::Image>(
            "camera",
            10,
            std::bind(&SearchColor::callback_color, this, std::placeholders::_1));
		// 创建发布者
		publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        RCLCPP_INFO(this->get_logger(), "search_color has been started.");
	}
private:
	// 处理图像 
	cv::Mat process_img(cv::Mat img) {
        // 转换为HSV
        cv::Mat hsv;
        cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
        // 根据颜色参数，提取颜色
        std::string color;
        this->get_parameter("color", color);
        /*
         * 似乎由于光线的问题，即使是使用了hsv空间也还是会有一些颜色识别不出来。
           考虑改变光源而不是阈值。
           考虑获取图像并确定其hsv阈值
           后面再做。  
         */
        cv::Scalar lower, upper;
        if (color == "red") {
            lower = cv::Scalar(140, 20, 20);
            upper = cv::Scalar(180, 255, 255);
        } else if (color == "blue") {
            lower = cv::Scalar(100, 20, 20);
            upper = cv::Scalar(124, 255, 255);
        } else if (color == "green") {
            lower = cv::Scalar(34, 20, 20);
            upper = cv::Scalar(90, 255, 255);
        } else if (color == "yellow") {
            // yellow
            lower = cv::Scalar(10, 20, 20);
            upper = cv::Scalar(34, 255, 255);
        }
        cv::Mat mask;
        cv::inRange(hsv, lower, upper, mask);
        // 腐蚀膨胀
        cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
        cv::erode(mask, mask, kernel);
        cv::dilate(mask, mask, kernel);
        // 返回mask
        return mask;
	}

    // 计算图像中白色区域的中心位置
    cv::Point2f get_center(cv::Mat mask) {
        // 计算白色区域的中心位置
        cv::Moments m = cv::moments(mask, true);
        cv::Point2f center(m.m10 / m.m00, m.m01 / m.m00);
        return center;
    }

	void callback_color(const sensor_msgs::msg::Image & msg) {
        RCLCPP_INFO(this->get_logger(), "search_color has received a msg.");
		cv_bridge::CvImagePtr CVPtr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
		cv::Mat img = CVPtr -> image;
        // 处理图像
        cv::Mat mask = process_img(img);
        // 判断mask中是否有白色
        RCLCPP_INFO(this->get_logger(), "开始寻找目标颜色");
        if (cv::countNonZero(mask) == 0) {
            // 没有白色，顺时针旋转直到有白色
            geometry_msgs::msg::Twist cmd_vel;
            cmd_vel.angular.z = 0.3;
            publisher_->publish(cmd_vel);
        } else {
            // 有白色，计算白色区域的中心位置
            RCLCPP_INFO(this->get_logger(), "有目标颜色");
            cv::Point2f center = get_center(mask);
            // 计算中心位置与图像中心的偏差
            cv::Point2f offset = center - cv::Point2f(img.cols / 2, img.rows / 2);
            // 发布速度
            geometry_msgs::msg::Twist cmd_vel;
            cmd_vel.linear.x = 0.1;
            cmd_vel.angular.z = -offset.x / 100;
            publisher_->publish(cmd_vel);
            // 判断白色区域是否位于图像中心，若是，结束
            if (std::abs(offset.x) < 10) {
                RCLCPP_INFO(this->get_logger(), "目标颜色位于图像中心");
                // 向前行驶8个单位
                geometry_msgs::msg::Twist cmd_vel;
                cmd_vel.linear.x = 0.8;
                publisher_->publish(cmd_vel);
                // 如果mask中白色区域大于40%，停下
                if (cv::countNonZero(mask) > 0.4 * mask.rows * mask.cols) {
                    RCLCPP_INFO(this->get_logger(), "目标颜色区域大于百分之40停下");
                    geometry_msgs::msg::Twist cmd_vel;
                    cmd_vel.linear.x = 0;
                    cmd_vel.angular.z = 0;
                    publisher_->publish(cmd_vel);
                    // 关闭节点
                    rclcpp::shutdown();
                }
            }
        }
        RCLCPP_INFO(this->get_logger(), "search_color has finished a msg.");        
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscrption_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    // // 将ignition的camera画面转发到ros2
    // ignition::transport::Node node;
    // ignition::transport::Node::Publisher pub = node.Advertise<ignition::msgs::Image>("/camera");
    rclcpp::spin(std::make_shared<SearchColor>());
    rclcpp::shutdown();
    return 0;
}

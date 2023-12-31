#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "mineral_interfaces/msg/mineral.hpp"
#include "mineral_interfaces/msg/mineral_array.hpp"
#include "mineral_interfaces/srv/fetch.hpp"


class Miner : public rclcpp::Node {
public:
    Miner() : Node("miner")
    {
        // 创建客户端
        client_ = this->create_client<mineral_interfaces::srv::Fetch>("fetch");
        
        // 订阅矿石数组
        subcription_ = this->create_subscription<mineral_interfaces::msg::MineralArray>(
            "mineral_array", 10, std::bind(&Miner::mineral_array_callback, this, std::placeholders::_1));          
        RCLCPP_INFO(this->get_logger(), "矿工已启动");

        // 创建发布者，发布给rviz2的位置
        publisher_ = this->create_publisher<geometry_msgs::msg::PointStamped>("rviz2_position", 10);
        arrow_publisher_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("point_trajectory", 10);
        
        marker_.points.push_back(current_position);
        marker_.header.frame_id = "map";
        marker_.type = visualization_msgs::msg::Marker::ARROW;
        // marker_.action = visualization_msgs::msg::Marker::ADD;
        marker_.color.r = 0.7;
        marker_.color.g = 0.1;
        marker_.color.b = 0.2;
        marker_.color.a = 0.7;
        marker_.scale.x = 0.1;
        marker_.scale.y = 0.1;
    }

private:
    rclcpp::Subscription<mineral_interfaces::msg::MineralArray>::SharedPtr subcription_; // 创建订阅者
    rclcpp::Client<mineral_interfaces::srv::Fetch>::SharedPtr client_; // 创建客户端
    rclcpp::Publisher<geometry_msgs::msg::PointStamped>::SharedPtr publisher_; // 创建发布者
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr arrow_publisher_; //轨迹发布者

    mineral_interfaces::msg::MineralArray mineral_array;  // 获取矿石数组
    geometry_msgs::msg::PointStamped rviz2_position;  // 打算发布给rviz2的位置
    visualization_msgs::msg::Marker marker_;  // Marker
    visualization_msgs::msg::MarkerArray marker_array_;  // MarkerArray,从消息接口的定义来看，完全是marker的数组

    geometry_msgs::msg::Point current_position;  // 获取当前位置
    //当前位置初始化为(0,0,0)
    geometry_msgs::msg::Point init_position()
    {
        geometry_msgs::msg::Point point;
        point.x = 0;
        point.y = 0;
        point.z = 0;
        return point;
    }
    
    // 订阅矿石数组的回调函数
    void mineral_array_callback(const mineral_interfaces::msg::MineralArray::SharedPtr msg)
    {
        // 如果矿石数为0,则不执行后续操作
        if (msg->minerals.size() == 0)
        {
            RCLCPP_INFO(this->get_logger(), "矿石数为0，挖完了再见");
            // 清除rviz2上的箭头
            marker_array_.markers.clear();
            arrow_publisher_->publish(marker_array_);
            // 强制结束当前节点
            rclcpp::shutdown();
            return;
        }
        RCLCPP_INFO(this->get_logger(), "收到矿石数组，共有%d个矿石", (int)(msg->minerals.size()));
        // 新的箭头
        marker_.points.clear();
        marker_.points.push_back(current_position);
        // 选择出距离自己最近的矿石的index
        int index = chooseMineral(msg);
        // 给marker的id,确保id不同
        marker_.id = index;
        // 输出
        RCLCPP_INFO(this->get_logger(), "成功选择出距离自己最近的矿石，编号为%d", index);
        // 更新当前位置，根据mineral自己的index属性选择出矿石，并将其位置赋值给当前位置
        for (int i = 0; i < (int)(msg->minerals.size()); i++)
        {
            if (msg->minerals[i].index == index)
            {
                current_position = msg->minerals[i].position;
                break;
            }
        }
        // 这个位置
        marker_.points.push_back(current_position);
        // 添加到marker_array_
        marker_array_.markers.push_back(marker_);
        arrow_publisher_->publish(marker_array_);
        // RCLCPP_INFO(this->get_logger(), "成功更新当前位置，它的位置是：(%f, %f, %f)",
        //     current_position.x,
        //     current_position.y,
        //     current_position.z);
        
        // 创建请求
        auto request = std::make_shared<mineral_interfaces::srv::Fetch::Request>();
        request->index = index;
        // 发送请求
        auto future = client_->async_send_request(request, std::bind(&Miner::send_request_callback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "已成功发送服务请求");

        // 发布给rviz2的位置
        rviz2_position.header.frame_id = "map";
        rviz2_position.header.stamp = this->now();
        rviz2_position.point = current_position;
        publisher_->publish(rviz2_position);
        // RCLCPP_INFO(this->get_logger(), "已成功发布给rviz2的位置，它的位置是：(%f, %f, %f)",
        //     rviz2_position.point.x,
        //     rviz2_position.point.y,
        //     rviz2_position.point.z);
    }

    // 发送服务的回调函数
    void send_request_callback(rclcpp::Client<mineral_interfaces::srv::Fetch>::SharedFuture future)
    {
        // 获取响应
        auto response = future.get();
        RCLCPP_INFO(this->get_logger(), "收到响应，矿石位置：(%f, %f, %f)，当前总的价值：%lf", response->position.x, response->position.y, response->position.z, response->price_all);
        response.reset();
    }

    // 计算矿石到自己当前位置的距离
    double distance(mineral_interfaces::msg::Mineral mineral)
    {
        double distance = sqrt(pow(mineral.position.x - current_position.x, 2) + pow(mineral.position.y - current_position.y, 2) + pow(mineral.position.z - current_position.z, 2));
        return distance;
    }

    // 选择出距离自己最近的矿石的index
    int chooseMineral(const mineral_interfaces::msg::MineralArray::SharedPtr msg)
    {
        // 计算出每个矿石到自己当前位置的距离，并与index配对
        std::vector<std::pair<double, int>> distance_index;
        for (int i = 0; i < (int)(msg->minerals.size()); i++)
        {
            distance_index.push_back(std::make_pair(distance(msg->minerals[i]), msg->minerals[i].index));
        }
        // 比较得出distance_index中每组键值对中的键的最小值
        std::pair<double, int> min_distance_index = distance_index[0];
        for (int i = 1; i < (int)distance_index.size(); i++)
        {
            if (distance_index[i].first < min_distance_index.first)
            {
                min_distance_index = distance_index[i];
            }
        }
        // 返回最小值对应的index
        return min_distance_index.second;
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Miner>());
    rclcpp::shutdown();
    return 0;
}
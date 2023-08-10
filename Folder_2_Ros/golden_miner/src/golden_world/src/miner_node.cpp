#include "rclcpp/rclcpp.hpp"
#include "mineral_interfaces/msg/mineral.hpp"
#include "mineral_interfaces/msg/mineral_array.hpp"
#include "mineral_interfaces/srv/fetch.hpp"


class Miner : public rclcpp::Node
{
public:
    Miner() : Node("miner")
    {
        // 订阅矿石数组
        subcription_ = this->create_subscription<mineral_interfaces::msg::MineralArray>(
            "mineral_array", 10, std::bind(&Miner::mineral_array_callback, this, std::placeholders::_1));   
        // 创建客户端
        client_ = this->create_client<mineral_interfaces::srv::Fetch>("fetch"); 
    }

    // 连接服务器
    void connect_to_server()
    {
        while (!client_->wait_for_service(std::chrono::seconds(1)))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(this->get_logger(), "客户端被中断");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "等待服务器启动");
        }
        RCLCPP_INFO(this->get_logger(), "已成功连接到服务器");
    }

    //发送服务
    void send_request()
    {
        // 创建请求
        auto request = std::make_shared<mineral_interfaces::srv::Fetch::Request>();
        request->index = get_index;
        // 发送请求
        auto future = client_->async_send_request(request);
        // 等待响应
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::FutureReturnCode::SUCCESS)
        {
            // 获取响应
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(), "收到响应，矿石位置：(%f, %f, %f)，当前价值：%lf", response->position.x, response->position.y, response->position.z, response->price);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "服务请求失败");
        }
    }


private:
    rclcpp::Subscription<mineral_interfaces::msg::MineralArray>::SharedPtr subcription_; // 创建订阅者
    rclcpp::Client<mineral_interfaces::srv::Fetch>::SharedPtr client_; // 创建客户端
    mineral_interfaces::msg::MineralArray mineral_array;  // 获取矿石数组

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

    int get_index = 0;  // 获取矿石编号
    
    // 订阅矿石数组的回调函数
    void mineral_array_callback(const mineral_interfaces::msg::MineralArray::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "收到矿石数组，共有%d个矿石", msg->minerals.size());
        // 选择出距离自己最近的矿石的index
        int index = chooseMineral(msg);
        // 
        get_index = index;
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
        for (int i = 0; i < msg->minerals.size(); i++)
        {
            distance_index.push_back(std::make_pair(distance(msg->minerals[i]), msg->minerals[i].index));
        }
        // 比较得出distance_index中每组键值对中的键的最小值
        std::pair<double, int> min_distance_index = distance_index[0];
        for (int i = 1; i < distance_index.size(); i++)
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

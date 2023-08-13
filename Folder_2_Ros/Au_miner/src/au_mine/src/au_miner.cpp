#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <au_interfaces/action/mineral.hpp>

using au_interfaces::action::Mineral;
class Miner : public rclcpp::Node
{
public:
    Miner() : Node("miner")
    {
        // 创建动作客户端
        client_ = rclcpp_action::create_client<Mineral>(this, "au_world_mine");
        
        // 创建参数，用于初始化矿石的数量
        this->declare_parameter<int>("mineral_count", 9);
    }

    // 发送矿石个数
    void send_total(int num) {
        // 链接服务端
        if (!client_->wait_for_action_server(10s)) {
            RCLCPP_ERROR(this->get_logger(), "服务链接失败")
            return;
        }

        // 发送矿石个数
        auto goal = Mineral::Goal();
        int total = this->get_parameter("mineral_count").as_int();
        goal.index = total;
        rclcpp_action::Client<Mineral>::SendGoalOptions optisons;
        options.goal_response_callback = std::bind(&ProgressActionClient::goal_response_callback, this, _1);
        options.feedback_callback = std::bind(&ProgressActionClient::feedback_callback, this, _1, _2);
        options.result_callback = std::bind(&ProgressActionClient::result_callback, this, _1);

        auto future = client_->async_send_goal(goal, optisons);
    }

    
private:
    rclcpp_action::Client<Mineral>::SharedPtr client_
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
    
    // 订阅矿石数组的回调函数
    void mineral_array_callback(const mineral_interfaces::msg::MineralArray::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "收到矿石数组，共有%d个矿石", (int)(msg->minerals.size()));
        // 选择出距离自己最近的矿石的index
        int index = chooseMineral(msg);
        // 输出
        RCLCPP_INFO(this->get_logger(), "成功选择出距离自己最近的矿石，编号为%d", index);
        send_request(index);
        RCLCPP_INFO(this->get_logger(), "已成功发送服务请求");
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

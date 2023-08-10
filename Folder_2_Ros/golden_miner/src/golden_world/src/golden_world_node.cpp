#include "rclcpp/rclcpp.hpp"
#include "mineral_interfaces/msg/mineral.hpp"
#include "mineral_interfaces/msg/mineral_array.hpp"
#include "mineral_interfaces/srv/fetch.hpp"

class GoldenWorld : public rclcpp::Node
{
public:
    GoldenWorld() : Node("golden_world")
    {
        // 创建参数，用于初始化矿石的数量
        this->declare_parameter<int>("mineral_count", 9);
        // 初始化矿石数组
        mineral_array = initMineralArray();
        // 创建发布者，发布矿石数组
        publisher_ = this->create_publisher<mineral_interfaces::msg::MineralArray>("mineral_array", 10);
        // 创建定时器，每秒发布一次矿石数组
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&GoldenWorld::timer_callback, this));
        
    }

private:
    // 随机生成平方和小于10的三个数，用数组表示
    geometry_msgs::msg::Point randomPosition()
    {
        geometry_msgs::msg::Point point;
        point.x = rand() % 10 / 10.0;
        point.y = rand() % 10 / 10.0;
        point.z = rand() % 10 / 10.0;
        return point;
    }

    // 使用参数，初始化MineralArray
    mineral_interfaces::msg::MineralArray initMineralArray()
    {
        mineral_interfaces::msg::MineralArray mineral_array;
        int mineral_count = this->get_parameter("mineral_count").as_int(); // 获取参数
        mineral_array.minerals.resize(mineral_count); // 重新设置数组大小
        for (int i = 1; i < mineral_count+1; i++)  // 编号从1开始
        {                        
            mineral_array.minerals[i].index = i;
            std::string kind_name = rand() % 2 ? "Au" : "Ag";
            mineral_array.minerals[i].kind = kind_name;
            mineral_array.minerals[i].position = randomPosition();
            mineral_array.minerals[i].price = kind_name == "Au" ? 80.8 : 40.4;
        }
        return mineral_array;
    }

    // 定时器回调函数
    void timer_callback()
    {
        // 发布矿石数组
        publisher_->publish(mineral_array);
        RCLCPP_INFO(this->get_logger(), "当前还有有%d个矿石", mineral_array.minerals.size());
    }
   
    // 声明数组
    mineral_interfaces::msg::MineralArray mineral_array;

    rclcpp::TimerBase::SharedPtr timer_; // 创建定时器
    rclcpp::Publisher<mineral_interfaces::msg::MineralArray>::SharedPtr publisher_;
    rclcpp::Service<mineral_interfaces::srv::Fetch>::SharedPtr service_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GoldenWorld>());
    rclcpp::shutdown();
    return 0;
}

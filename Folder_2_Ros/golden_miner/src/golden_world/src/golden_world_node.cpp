#include "rclcpp/rclcpp.hpp"

#include "mineral_interfaces/msg/mineral.hpp"
#include "mineral_interfaces/msg/mineral_array.hpp"
#include "mineral_interfaces/srv/fetch.hpp"

class GoldenWorld : public rclcpp::Node
{
public:
    GoldenWorld() : Node("golden_world") {
        // 创建参数，用于初始化矿石的数量
        this->declare_parameter<int>("mineral_count", 9);
        mineral_array = initMineralArray();
        // 创建发布者，发布矿石数组
        publisher_ = this->create_publisher<mineral_interfaces::msg::MineralArray>("mineral_array", 10);
        // 创建定时器，每秒发布一次矿石数组
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&GoldenWorld::timer_callback, this));
        // 创建服务，用于接收矿工的请求
        service_ = this->create_service<mineral_interfaces::srv::Fetch>("fetch", std::bind(&GoldenWorld::fetch,
        this, std::placeholders::_1, std::placeholders::_2));
    }

private:
    // 随机生成平方和小于10的三个数，用数组表示
    geometry_msgs::msg::Point randomPosition() {
        geometry_msgs::msg::Point point;
        point.x = rand() % 10 / 10.0;
        point.y = rand() % 10 / 10.0;
        point.z = rand() % 10 / 10.0;
        return point;
    }

    // 使用参数，初始化MineralArray
    mineral_interfaces::msg::MineralArray initMineralArray() {
        // 初始化head
        mineral_array.head.stamp = this->now();
        mineral_array.head.frame_id = "world";
        // 初始化minerals     
        int mineral_count = this->get_parameter("mineral_count").as_int(); // 获取参数
        for (int i = 1; i < mineral_count+1; i++)  // 编号从1开始
        {                        
            // 输出
            RCLCPP_INFO(this->get_logger(), "在添加第%d个矿石", i);
            mineral_array.minerals.push_back(createMineral(i));
        }
        return mineral_array;
    }

    // 创建一个矿石数组
    mineral_interfaces::msg::Mineral createMineral(int index) {   
        if (index < 1 || index > 10)
        {
            RCLCPP_ERROR(this->get_logger(), "矿石编号必须在1-10之间");
            return mineral_interfaces::msg::Mineral();
        }
        auto mineral = std::make_shared<mineral_interfaces::msg::Mineral>();
        mineral->index = index;
        std::string kind_name = rand() % 2 ? "Au" : "Ag";
        mineral->kind = kind_name;
        mineral->position = randomPosition();
        mineral->price = kind_name == "Au" ? 80.8 : 40.4;
        return *mineral;
    }

    // 定时器回调函数
    void timer_callback() {
        // 发布矿石数组
        publisher_->publish(mineral_array);
        RCLCPP_INFO(this->get_logger(), "当前还有%d个矿石", int(mineral_array.minerals.size()));
        // 检查矿石是否已经被挖完，如果是，则结束程序，并告诉矿工
        if (mineral_array.minerals.size() == 0)
        {
            RCLCPP_INFO(this->get_logger(), "矿石已经被挖完，程序结束");
            rclcpp::shutdown();
        }
    }

    // 服务回调函数
    void fetch(const std::shared_ptr<mineral_interfaces::srv::Fetch::Request> request,
               std::shared_ptr<mineral_interfaces::srv::Fetch::Response> response) {
        // 获取请求中的矿石编号
        int index = request->index;
        // 在矿石数组中查找该编号的矿石
        for (int i = 0; i < (int)mineral_array.minerals.size(); i++)
        {
            if (mineral_array.minerals[i].index == index)
            {
                // 找到矿石，将其从数组中删除
                
                response->position = mineral_array.minerals[i].position;
                price_all = price_all + mineral_array.minerals[i].price;
                response->price_all = price_all;
                RCLCPP_INFO(this->get_logger(), "矿石%d已被挖走", index);
                mineral_array.minerals.erase(mineral_array.minerals.begin() + i);
                return;
            }
        }
    }

    mineral_interfaces::msg::MineralArray mineral_array;
    rclcpp::TimerBase::SharedPtr timer_;  // 创建定时器
    rclcpp::Publisher<mineral_interfaces::msg::MineralArray>::SharedPtr publisher_;
    rclcpp::Service<mineral_interfaces::srv::Fetch>::SharedPtr service_;
    // 定义一个总价值
    double price_all = 0;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GoldenWorld>());
    rclcpp::shutdown();
    return 0;
}

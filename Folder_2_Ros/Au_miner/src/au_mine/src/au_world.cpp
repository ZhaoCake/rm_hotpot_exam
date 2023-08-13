#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <au_interfaces/action/mineral.hpp>

using au_interfaces::action::Mineral;

class GoldenWorld : public rclcpp::Node
{
public:
    GoldenWorld() : Node("golden_world")
    {
        server_ = rclcpp_action::create_server<Mineral>(
            this,
            "au_world_mine",
            std::bind(&GoldenWorld::handle_total, this),
            std::bind(&GoldenWorld::handle_cancel, this),
            std::bind(&GoldenWorld::handle_accepted, this)
        )
    }

    

private:
    rclcpp_action::Server<Mineral>::SharedPtr server_;

    au_interfaces::action::Mineral minerals

    // 处理提交的总个数
    rclcpp_action::GoalResponse handle_total(const rclcpp_action::GoalUUID &uuid,
    std::shared_ptr<const Mineral::Goal> goal) {
        (void)uuid;
        int total = goal->total;
        

        
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }


    // 处理取消请求
    rclcpp_action::CancelResponse handle_cancel(std::shared_ptr<rclcpp_action::ServerGoalHandle<Mineral>> goal_handle)
    {
        (void)goal_handle;
        RCLCPP_INFO(this->get_logger(), "接收到任务取消请求");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    //生成连续反馈与最终响应
    void handle_accepted(std::shared_ptr<rclcpp_action::ServerGoalHandle<Mineral>> goal_handle)
    {
        
    }
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
    au_interfaces::action::Mineral initMineral() {
        // 初始化head
        
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
    mineral_interfaces::msg::Mineral createMineral(int index)
    {   
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
    void timer_callback()
    {
        // 检查矿石是否已经被挖完，如果是，则结束程序，并告诉矿工
        if (mineral_array.minerals.size() == 0)
        {
            RCLCPP_INFO(this->get_logger(), "矿石已经被挖完，程序结束");
            rclcpp::shutdown();
        }
        
        // 发布矿石数组
        publisher_->publish(mineral_array);
        RCLCPP_INFO(this->get_logger(), "当前还有%d个矿石", int(mineral_array.minerals.size()));
    }

    // 服务回调函数
    void fetch(const std::shared_ptr<mineral_interfaces::srv::Fetch::Request> request,
               std::shared_ptr<mineral_interfaces::srv::Fetch::Response> response)
    {
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
   
    
    
    rclcpp::TimerBase::SharedPtr timer_;  // 创建定时器
    rclcpp::Publisher<mineral_interfaces::msg::MineralArray>::SharedPtr publisher_;
    rclcpp::Service<mineral_interfaces::srv::Fetch>::SharedPtr service_;
    // 定义一个总价值
    double price_all = 0;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GoldenWorld>());
    rclcpp::shutdown();
    return 0;
}

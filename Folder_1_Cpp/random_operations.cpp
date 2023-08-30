// Copyright 2023 <ZhaoCake>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <functional>
#include <iomanip>
#include <signal.h>

// 创建一个全局变量，用于标记程序是否停止
bool app_stopped = false;

void sigint_handler(int sig){
	if(sig == SIGINT){
		// ctrl+c退出时执行的代码
		std::cout << "检测到ctrl+c退出!" << std::endl;
		app_stopped = true;
	}
}

// 创建随即数据，可指定数据个数
std::vector<float> createRandomData(int num) {
    u_int seed = time(NULL);
    std::vector<float> data;
    //产生数据不能有0，并且有num个，生成的是1到2之间的随机数
    for (int i = 0; i < num; i++) {
        data.push_back((float)rand_r(&seed) / RAND_MAX + 1);
    }
    return data;
}

// 操作1：求和
float operation1(const std::vector<float>& data) {
    float sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += data[i];
    }
    std::cout << "sum:\t";
    return sum;
}

// 操作2：求均值
float operation2(const std::vector<float>& data) {
    auto sum = operation1(data);
    auto mean = sum / data.size();
    std::cout << "\rmean:\t";
    return mean;
}

// 操作3：求方差
float operation3(const std::vector<float>& data) {
    auto mean = operation2(data);
    float sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    std::cout << "\rvariance: ";
    return sum;
}

// 操作4：求累乘
float operation4(const std::vector<float>& data) {
    float product = 1;
    for (int i = 0; i < data.size(); i++) {
        product *= data[i];
    }
    std::cout << "product: ";
    return product;
}

// 定义定时器，定时器每500ms执行一次，每次执行随机选择一种操作
void createTimerLoop(int period,
        const std::vector<float>& data,
        std::vector<std::function<float(const std::vector<float>&)>>&
        operations) {
    // 等待500ms
    usleep(period * 1000);
    // 从operations中随机取出一种操作
    auto operation = operations[rand() % operations.size()];  // 使用了函数指针
    // 执行操作
    auto result = operation(data);
    // 输出结果，不使用科学计数法并保留两位小数（日志文件中不做变动）
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    // 从评分细则来看，输出需要说明是什么操作，但是函数指针无法获取函数名，所以直接在之前输出
    // 不过这样有割裂感，可以把操作函数写为返回void类型。但是这样的话一个返回空值的运算函数多少有些丧失其原本的意义，故不采用
}

// 主函数, 可以通过命令行参数指定数据个数, argc
int main(int argc, char * argv[]) {
    int num = 100;
    // 可通过命令行参数修改num
    if (argc > 1) {
        num = atoi(argv[1]);
    }
    // 检测是否有ctrl+c信号
    signal(SIGINT, sigint_handler);

    // 参数使用实例： ./random_operations 100
    // 使用函数获取随机数据，从而可以指定数据个数
    std::vector<float> data = createRandomData(num);
    std::vector<std::function<float(const std::vector<float>&)>> operations;
    // 可以继续写operation5、operation6等等，使用push_back添加到operations中
    operations.push_back(operation1);
    operations.push_back(operation2);
    operations.push_back(operation3);
    operations.push_back(operation4);
    while (true) {
        createTimerLoop(500, data, operations);
        // 检测是否有ctrl+c信号
        if(app_stopped){
            break;
        }
    }
    return 0;
}

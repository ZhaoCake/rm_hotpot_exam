#include <vector>
#include <iostream>
#include <functional>


// 创建随即数据，可指定数据个数
std::vector<float> createRandomData(int num)
{
    std::vector<float> data;
    for (int i = 0; i < num; i++)
    {
        data.push_back(rand() % num);
    }
    return data;
}

// 操作1：求和
float operation1(std::vector<float>& data)
{
    float sum = 0;
    for (int i = 0; i < data.size(); i++)
    {
        sum += data[i];
    }
    return sum;
}

// 操作2：求均值
float operation2(std::vector<float>& data)
{
    auto sum = operation1(data);
    auto mean = sum / data.size();
    return mean;
}

// 操作3：求方差
float operation3(std::vector<float>& data)
{
    auto mean = operation2(data);
    float sum = 0;
    for (int i = 0; i < data.size(); i++)
    {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sum;
}

// 操作4：求累乘
float operation4(std::vector<float>& data)
{
    auto product = 1;
    for (int i = 0; i < data.size(); i++)
    {
        product *= data[i];
    }
    return product;
}

// 定义定时器，定时器每500ms执行一次，每次执行随机选择一种操作
float createTimerLoop(int period, std::vector<float>& data, std::vector<std::function<float (std::vector<float>&)>>& operations)
{
    // 从operations中随机取出一种操作
    auto operation = operations[rand() % operations.size()];
    // 执行操作
    auto result = operation(data);
    // 输出结果
    std::cout << result << std::endl;
}

// 主函数
int main()
{
    int num = 100;
    // 使用函数获取随机数据，从而可以指定数据个数
    std::vector<float> data = createRandomData(num);
    std::vector<std::function<float (std::vector<float>&)>> operations;
    // 可以继续写operation5、operation6等等，使用push_back添加到operations中
    operations.push_back(operation1);
    operations.push_back(operation2);
    operations.push_back(operation3);
    operations.push_back(operation4);
    while (true)
    {
        createTimerLoop(500, data, operations);
    }
}

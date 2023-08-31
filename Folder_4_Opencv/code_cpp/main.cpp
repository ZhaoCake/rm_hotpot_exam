#include <iostream>
#include <opencv2/opencv.hpp>
#include "preprocess.h"

#include "predict.h"
// 虽然我的预测函数不在这个类里面，但是依然有许多函数，比如判断弧度值符号等功能是需要使用的

float next_frame(int pred_num, int frame_number) {
    // 按道理是需要知道这个周期的起始位置的，但是由于启动时差不多是一样的，姑且按照余弦函数来做
    int x = (frame_number + pred_num) % 201;
    return cos((CV_PI * 2 / 201) * x) * 0.040201594897572156 + 0.06054993193418074;
}

float predict_new(int frame_num) {
    float delta_angle = 0;
    for (int i = 0; i < 30; i++) {
        delta_angle += next_frame(i, frame_num);
    }
    return delta_angle;
}

int main() {
    // 视频路径
    std::string video_path = "/home/zhaocake/Documents/single_program/rm_hotpot_exam/Folder_4_Opencv/code_cpp/src/blue_dark.mp4";
    // 打开摄像头
    cv::VideoCapture cap(video_path);
    // 判断是否成功打开
    if (!cap.isOpened()) {
        std::cout << "can not open the camera" << std::endl;
        return -1;
    }
    // 创建窗口
    cv::namedWindow("video", cv::WINDOW_AUTOSIZE);
    // 创建一个Mat对象，用于存储每一帧的图像
    cv::Mat frame;
    auto pre_hand = std::make_shared<preprocess>();
    auto predictor = std::make_shared<predict>();
    // 循环读取每一帧
    while (true) {
        // 读取当前帧
        cap >> frame;
        // 判断是否读取成功
        if (frame.empty()) {
            std::cout << "can not read the frame" << std::endl;
            break;
        }
        // 记录当前时间
        auto start = cv::getTickCount();
        pre_hand->get_image(frame);
        auto arrow = pre_hand->process_img(frame);
        auto cen_arrow = arrow[0];
        auto obj_arrow = arrow[1];
//        auto cen_angle = predictor->read_cen(cen_arrow);
        auto obj_angle = predictor->cvt_angle(obj_arrow);
        // 获取当前帧数
        int frame_num = cap.get(cv::CAP_PROP_POS_FRAMES);
        float now_obj_angle = obj_angle + predict_new(frame_num);

        auto box = pre_hand->draw_obj(now_obj_angle);
        // 记录当前时间
        auto end = cv::getTickCount();
        // 计算时间差
        auto time = (end - start) / cv::getTickFrequency() * 1000;

        // 输出box
        std::cout << "\ttime: " << time << "\tbox: " << box << std::endl;

        // 显示当前帧
        // cv::imshow("video", frame);
        // 等待30ms，如果按下ESC键则退出循环
        if (cv::waitKey(1) == 27) {
            break;
        }
    }
    // 释放VideoCapture对象
    cap.release();
    // 关闭窗口
    cv::destroyAllWindows();
    return 0;
}

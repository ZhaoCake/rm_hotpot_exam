//
// Created by zhaocake on 23-8-31.
//

#include "preprocess.h"

// 获取轮廓
auto preprocess::get_contours(cv::Mat &img) -> std::vector<std::vector<cv::Point>> {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    // 转为灰度图
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    // 二值化
    cv::threshold(img, img, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    // 先膨胀后腐蚀
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(11, 11));
    cv::dilate(img, img, element);
    cv::erode(img, this->mask, element);
    // 寻找轮廓
    cv::findContours(this->mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    return contours;
}

// 计算轮廓面积
auto preprocess::get_area(std::vector<std::vector<cv::Point>> &contours) -> std::vector<double> {
    std::vector<double> area;
    for (auto &contour : contours) {
        area.push_back(cv::contourArea(contour));
    }
    return area;
}

// 构造函数
preprocess::preprocess() {
    this->img = nullptr;
}

cv::Point preprocess::return_circle_heart() {
    return this->center_point;
}

void preprocess::get_image(cv::Mat &src_img) {
    this->img = &src_img;
    this->img_copy = src_img.clone();
    int height = this->img->rows;
    int width = this->img->cols;
    this->img_copy.colRange(0, int(width * 0.3)) = 0;
    this->img_copy.colRange(int(width * 0.7), width) = 0;
//    # 将图像中心10%复制到center中
//        self.center = self.src_img[int(height * 0.44):int(height * 0.51),
//                               int(width * 0.48):int(width * 0.52)]
    this->center = this->img->rowRange(int(height * 0.44), int(height * 0.51)).colRange(int(width * 0.48),
                                                                                         int(width * 0.52));
}

void preprocess::get_circle_heart() {
    auto contours = get_contours(this->center);
    auto area = get_area(contours);
    // cpp的异常处理，类似于python的try except，try找出最大轮廓，except则返回0
    try {
        auto max_area = std::max_element(area.begin(), area.end());
        auto max_index = std::distance(area.begin(), max_area);
        auto max_contour = contours[max_index];
        // 获取最大轮廓外接矩形
        auto rect = cv::minAreaRect(max_contour);
        // 获取中心
        this->center_point = rect.center;
        // 把中心坐标变换回原图坐标
        this->center_point.x += int(this->img_copy.cols * 0.48);
        this->center_point.y += int(this->img_copy.rows * 0.44);
        // 获得四个顶点
        cv::Point2f vertices[4];
        rect.points(vertices);
        try {
            // 分别求出邻边长度
            auto chang = cv::norm(vertices[0] - vertices[1]);
            auto kuan = cv::norm(vertices[1] - vertices[2]);
            if (chang > kuan) {
                this->cen_arrow = vertices[0] - vertices[1];
            } else {
                this->cen_arrow = vertices[1] - vertices[2];
            }
            this->cen_arrow = this->cen_arrow / cv::norm(this->cen_arrow) * 100;
        } catch (std::exception &e) {
            std::cout << "没有找到中心箭头" << std::endl;
        }
        // 将vertices转换为int类型
        for (auto &vertex : vertices) {
            vertex.x = int(vertex.x);
            vertex.y = int(vertex.y);
        }
        // 坐标变换回原图坐标
        for (auto &vertex : vertices) {
            vertex.x += int(this->img_copy.cols * 0.48);
            vertex.y += int(this->img_copy.rows * 0.44);
        }
        // 画出外接矩形
        for (int i = 0; i < 4; i++) {
            cv::line(*this->img, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 0, 255), 3);
        }
    } catch (std::exception &e) {
        this->center_point = cv::Point(0, 0);
        std::cout << "没有找到轮廓" << std::endl;
    }
}

void preprocess::get_object() {
    // 在this->img_copy中删去this->center所在的区域
    int height = this->img_copy.rows;
    int width = this->img_copy.cols;
    this->img_copy.rowRange(int(height * 0.44), int(height * 0.51)).colRange(int(width * 0.48), int(width * 0.52)) = 0;
    auto contours = get_contours(this->img_copy);
    auto area = get_area(contours);
    try {
        // 从这些轮廓中找出最小轮廓
        auto min_area = std::min_element(area.begin(), area.end());
        auto min_index = std::distance(area.begin(), min_area);
        auto min_contour = contours[min_index];
        // 获取最小轮廓外接矩形
        auto rect = cv::minAreaRect(min_contour);
        // 画出rect
        cv::Point2f vertices[4];
        rect.points(vertices);
        for (auto &vertex : vertices) {
            vertex.x = int(vertex.x);
            vertex.y = int(vertex.y);
        }
        for (int i = 0; i < 4; i++) {
            cv::line(*this->img, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 232, 123), 3);
        }
        this->obj_arrow = rect.center - this->center_point;
//        this->obj_arrow = this->obj_arrow / cv::norm(this->obj_arrow) * 100;
        this->obj_weight = rect.size.width;
        this->obj_height = rect.size.height;
        this->obj_distance = cv::norm(this->obj_arrow);
    } catch (std::exception &e) {
        std::cout << "没有找到第二个轮廓" << std::endl;
    }
}

std::vector<cv::Point2f> preprocess::process_img(cv::Mat &src_img) {
    this->get_image(src_img);
    this->get_circle_heart();
    this->get_object();
    std::vector<cv::Point2f> result;
    result.push_back(this->cen_arrow);
    result.push_back(this->obj_arrow);
    return result;
}

std::vector<cv::Point2f> preprocess::draw_obj(float theta) {
    // 先把弧度数转化为像素坐标
    cv::Point2f obj_arrow_e;
    obj_arrow_e.x = this->obj_distance * cos(theta) + this->center_point.x;
    obj_arrow_e.y = this->obj_distance * sin(theta) + this->center_point.y;
    // 使长的与theta在同一方向上
    if (this->obj_weight > this->obj_height) {
        // 使用指针交换
        float temp = this->obj_weight;
        this->obj_weight = this->obj_height;
        this->obj_height = temp;}
    // 弧度转成角度
    float angle = theta * 180 / CV_PI;
    // 在第一象限时，不需要转换
    if (theta >=0 and theta <= 90) {
        float temp = this->obj_weight;
        this->obj_weight = this->obj_height;
        this->obj_height = temp;
    } else if (theta > 90 and theta <= 180) {
        angle = angle - 90;
    } else if (theta > 180 and theta <= 270) {
        angle = angle - 180;
        float temp = this->obj_weight;
        this->obj_weight = this->obj_height;
        this->obj_height = temp;
    } else if (theta > 270 and theta < 360) {
        angle = angle - 270;
    }

    cv::RotatedRect rect(obj_arrow_e, cv::Size2f(this->obj_weight, this->obj_height), angle);
    cv::Point2f vertices[4];
    rect.points(vertices);
    for (auto &vertex : vertices) {
        vertex.x = int(vertex.x);
        vertex.y = int(vertex.y);
    }

    // 画出外接矩形
    for (int i = 0; i < 4; i++) {
        cv::line(*this->img, vertices[i], vertices[(i + 1) % 4], cv::Scalar(0, 255, 0), 3);
    }

    std::vector<cv::Point2f> result;
    // 把vertex的四个点写入
    for (auto &vertex : vertices) {
        result.push_back(vertex);
    }
    return result;
}

preprocess::~preprocess() = default;
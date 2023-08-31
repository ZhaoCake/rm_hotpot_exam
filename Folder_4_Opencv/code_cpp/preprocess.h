//
// Created by zhaocake on 23-8-31.
//

#ifndef CODE_CPP_PREPROCESS_H
#define CODE_CPP_PREPROCESS_H

#include <opencv2/opencv.hpp>

class preprocess {
public:
    cv::Mat mask;

    preprocess();
    ~preprocess();
    cv::Point return_circle_heart();
    void get_image(cv::Mat &src_img);
    std::vector<cv::Point2f> process_img(cv::Mat &src_img);
    std::vector<cv::Point2f> draw_obj(float theta);

private:
    cv::Mat *img;
    cv::Mat img_copy;
    cv::Mat center;
    cv::Point2f center_point {(0, 0)};
    cv::Point cen_arrow;
    cv::Point obj_arrow;
    float obj_weight = 0;
    float obj_height = 0;
    float obj_distance = 0;

    std::vector<std::vector<cv::Point>> get_contours(cv::Mat &img);
    static std::vector<double> get_area(std::vector<std::vector<cv::Point>> &contours);

    void get_circle_heart();
    void get_object();
};


#endif //CODE_CPP_PREPROCESS_H

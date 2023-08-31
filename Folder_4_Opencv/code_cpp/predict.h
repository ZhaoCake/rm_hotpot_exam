//
// Created by zhaocake on 23-8-31.
//

#ifndef CODE_CPP_PREDICT_H
#define CODE_CPP_PREDICT_H

#include <opencv2/opencv.hpp>

class predict {
public:
    predict();
    ~predict();
    static float cvt_angle(const cv::Point2f& arrow);
    float read_cen(const cv::Point2f& cen_arrow);
    void final_predict();


private:
    float cen_angle = 0;
    float obj_angle = 0;
    std::vector<float> cen_angle_vec;
    bool state = false;
    bool sign_state = false;
    std::string orientation;
    std::vector<float> angle_velocity_list;
    std::function<float(float)> f = [](float x) { return x; };

    void get_cen_data();
    void judge_direction_rotation();
    void preprocess_angle_vel();


};


#endif //CODE_CPP_PREDICT_H

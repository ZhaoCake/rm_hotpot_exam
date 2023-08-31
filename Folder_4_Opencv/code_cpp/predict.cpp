//
// Created by zhaocake on 23-8-31.
//
/*
 * 我是five,这个低通滤波和寻找波峰波谷的函数，我虽然知道cpp也有开源库可以做，但是还是放弃了这个打算
 * 自己写这个的话，我还是暂时做不到啊。以后在避无可避的情况下会去做吧。
 *
 * 毕竟我在python中已经得到可用的预测函数了
 * */

#include "predict.h"

predict::predict() = default;

predict::~predict() = default;

float predict::cvt_angle(const cv::Point2f& arrow) {
    // 预设angle为空值float
    float angle = 0;
    try {
        float angle_exist = atan(arrow.y / arrow.x);
        if (arrow.x < 0) {
            angle_exist += CV_PI;
        }
        if (angle_exist < 0) {
            angle_exist += 2 * CV_PI;
        }
        return angle_exist;
    } catch (std::exception &e){
        std::cout << "error: " << e.what() << std::endl;
        return angle;
    }

}

float predict::read_cen(const cv::Point2f& cen_arrow) {
    auto crt_cen_angle = this->cvt_angle(cen_arrow);
    float cen_angle_temp = 0;
    // 如果crt_cen_angle不为空的话
    if (crt_cen_angle != 0) {
        if (this->cen_angle != 0){
            if (abs(crt_cen_angle - this->cen_angle) > 1.55) {
                this->sign_state = true;
            } else {
                this->sign_state = false;
            }
            if (!this->sign_state) {
                cen_angle_temp = crt_cen_angle;
            } else {
                float mid_cen_angle = crt_cen_angle + (float)CV_PI;
                if (mid_cen_angle > 2 * CV_PI) {
                    mid_cen_angle -= 2 * CV_PI;
                }
                cen_angle_temp = mid_cen_angle;
            }
            return cen_angle_temp;
        } else {
            cen_angle_temp = crt_cen_angle;
            return cen_angle_temp;
        }
    }
}

void predict::get_cen_data() {
    auto cen_angle_temp = this->cen_angle;
    if (cen_angle_temp != 0) {
        this->cen_angle_vec.push_back(cen_angle_temp);
    }
    if (this->cen_angle_vec.size() > 10) {
        this->judge_direction_rotation();
        // 这里没法做和python一样的判断啊，希望他们在判断空值上有所不同吧
        float angular_velocity = (this->cen_angle_vec.end()) - (this->cen_angle_vec.end() - 2);
        this->angle_velocity_list.push_back(angular_velocity);
        if (this->angle_velocity_list.size() > 20) {
            this->preprocess_angle_vel();
        }
    }
}

void predict::judge_direction_rotation() {
    int interpolation_num = 2;
    std::vector<float> cen_angle_vec_temp;
    if (this->cen_angle_vec.size() > 100) {
        cen_angle_vec_temp.assign(this->cen_angle_vec.end() - 100, this->angle_velocity_list.end());
    } else {
        cen_angle_vec_temp.assign(this->cen_angle_vec.begin(), this->angle_velocity_list.end());
    }
    // 小于0的值都加上2pi
    for (auto &i : cen_angle_vec_temp) {
        if (i < 0) {
            i += 2 * CV_PI;
        }
    }
    // 对于cen_angle_vec_temp插值，在前面插入两个0,存为temp2
    std::vector<float> temp2;
    temp2.push_back(0);
    temp2.push_back(0);
    for (auto &i : cen_angle_vec_temp) {
        temp2.push_back(i);
    }
    // temp2删除最后两个值
    temp2.erase(temp2.end() - 2, temp2.end());
    // 用temp减去temp2，存为temp3
    std::vector<float> temp3;
    for (float i : temp2) {
        temp3.push_back(i - i);
    }
    // 获得temp3中有多少0
    float zero_num = 0;
    for (auto &i : temp3) {
        if (i == 0) {
            zero_num++;
        }
    }
    float ratio = zero_num / temp3.size();
    if (ratio < 0.5) {
        this->orientation = "clockwise";
    } else {
        this->orientation = "anticlockwise";
    }
}

void predict::preprocess_angle_vel() {
    // 去除angle_velocity_list中的0
    std::vector<float> angle_velocity_list_temp;
    for (auto &i : this->angle_velocity_list) {
        if (i != 0) {
            angle_velocity_list_temp.push_back(i);
        }
    }
    // 去除大于0.2的值
    std::vector<float> angle_velocity_list_temp2;
    for (auto &i : angle_velocity_list_temp) {
        if (i < 0.2) {
            angle_velocity_list_temp2.push_back(i);
        }
    }
    // 把非正值改为前一个值
    for (int i = 0; i < angle_velocity_list_temp2.size(); i++) {
        if (angle_velocity_list_temp2[i] <= 0) {
            angle_velocity_list_temp2[i] = angle_velocity_list_temp2[i - 1];
        }
    }
    std::vector<float> angle_velocity_list_temp3;
    // 平滑滤波，并且狠狠平滑，平滑窗格为20
    for (int i = 0; i < angle_velocity_list_temp2.size(); i++) {
        if (i < 20) {
            angle_velocity_list_temp3.push_back(angle_velocity_list_temp2[i]);
        } else {
            float sum = 0;
            for (int j = 0; j < 20; j++) {
                sum += angle_velocity_list_temp2[i - j];
            }
            angle_velocity_list_temp3.push_back(sum / 20);
        }
    }
    this->angle_velocity_list = angle_velocity_list_temp3;
}

void predict::final_predict() {
    this->get_cen_data();
    if (this->angle_velocity_list.size() >= 100) {
        int peak_value = 0;
        int trough_value = 0;
        std::vector<int> preiod_list;
    }
}
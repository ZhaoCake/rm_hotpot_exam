import cv2
import numpy as np
import traceback
from extend_exam_nt import get_center

import numpy as np


class KalmanFilter:
    def __init__(self, dt, process_noise, measurement_noise):
        # 状态转移矩阵
        self.F = np.array([[1, 0, dt, 0], [0, 1, 0, dt], [0, 0, 1, 0],
                           [0, 0, 0, 1]])  # 有加速度位的状态转移矩阵

        # 测量矩阵
        self.H = np.array([[1, 0, 0, 0], [0, 1, 0,
                                          0]])  # 没有加速度位的测量值，否则和state叉乘就是4维了

        # 过程噪声协方差矩阵
        self.Q = np.array([[0.25 * dt**4, 0, 0.5 * dt**3, 0],
                           [0, 0.25 * dt**4, 0, 0.5 * dt**3],
                           [0.5 * dt**3, 0, dt**2, 0],
                           [0, 0.5 * dt**3, 0, dt**2]]) * process_noise

        # 测量噪声协方差矩阵
        self.R = np.array([[measurement_noise, 0], [0, measurement_noise]])

        # 状态向量
        self.state = np.zeros((4, 1))

        # 协方差矩阵
        self.P = np.eye(4)

    def predict(self):
        # 预测步骤
        self.state = np.dot(self.F, self.state)
        self.P = np.dot(np.dot(self.F, self.P), self.F.T) + self.Q
        return self.state[:2]

    def update(self, measurement):
        # 更新步骤
        y = measurement - np.dot(self.H, self.state)
        S = np.dot(np.dot(self.H, self.P), self.H.T) + self.R
        K = np.dot(np.dot(self.P, self.H.T), np.linalg.inv(S))
        self.state = self.state + np.dot(K, y)
        self.P = np.dot(np.eye(4) - np.dot(K, self.H), self.P)
        return self.state[:2]


def main():
    """二阶kalman滤波预测坤体运动"""
    video_path = "KalmanFilter_test_video.mp4"
    cap = cv2.VideoCapture(video_path)
    # 创建Kalman滤波器对象
    dt = 1  # 时间变化量取为1，表明的是一帧而不是时间间隔，在读视频里，一帧就是间隔
    process_noise = 0.1  # 过程噪声方差
    measurement_noise = 3  # 测量噪声方差，给的比较大，否则太相信这个值了
    kalman_filter = KalmanFilter(dt, process_noise, measurement_noise)
    while cap.isOpened():
        ret, frame = cap.read()
        if ret:
            center, r = get_center(frame)  # r已经在初始化的时候取得
            # 预测
            predicted_state = kalman_filter.predict()
            # 更新
            filtered_state = kalman_filter.update(
                np.array(center).reshape(2, 1))
            print("滤波值：", filtered_state.flatten())
            print("状态值：", kalman_filter.state.flatten())  # 可以看到，状态值中包含了速度信息
            try:
                cv2.circle(frame,
                           (int(filtered_state[0]), int(filtered_state[1])), r,
                           (123, 0, 43), 2)
            except cv2.error as e:
                traceback.print_exc()
            # 在图片左上角显示图例说明
            cv2.putText(frame, "green: true position", (10, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            cv2.putText(frame, "purple: filter position", (10, 50),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (123, 0, 43), 2)
            cv2.imshow("True", frame)
            if cv2.waitKey(30) & 0xFF == ord('q'):
                break
        else:
            break


if __name__ == '__main__':
    main()

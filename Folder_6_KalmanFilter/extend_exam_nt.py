import cv2
import numpy as np
from KalmanFilter import Kalman


def get_center(frame):
    """获取蓝球中心"""
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    # 提取蓝色区域
    lower_blue = np.array([100, 43, 46])
    upper_blue = np.array([124, 255, 255])
    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    # 腐蚀膨胀
    kernel = np.ones((5, 5), np.uint8)
    mask = cv2.erode(mask, kernel, iterations=2)
    mask = cv2.dilate(mask, kernel, iterations=2)
    # 寻找轮廓
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL,
                                           cv2.CHAIN_APPROX_SIMPLE)
    # 最大轮廓的最大外接圆
    max_contour = max(contours, key=cv2.contourArea)
    (x, y), radius = cv2.minEnclosingCircle(max_contour)
    center = (int(x), int(y))
    radius = int(radius)
    # 绘制轮廓
    cv2.circle(frame, center, radius, (0, 255, 0), 3)
    # 绘制中心
    cv2.circle(frame, center, 2, (0, 0, 255), 2)
    return center, radius


def main():
    """基于一维卡尔曼滤波器的运动预测"""
    # 读入视频，对每一帧进行处理
    video_path = "KalmanFilter_test_video.mp4"
    cap = cv2.VideoCapture(video_path)
    kalman_filter_x = Kalman()
    kalman_filter_y = Kalman()
    kalman_filter_x.get_args(r=0.3, q=0.1)  # 在这个任务中，测量值实在是没什么误差
    kalman_filter_y.get_args(r=0.3, q=0.1)  # 但是为了演示，还是假定它有一些误差
    while cap.isOpened():
        ret, frame = cap.read()
        if ret:
            center, r = get_center(frame)
            kalman_filter_x.kalman_adaptive(
                center[0])  # 默认参数update=1，是会使用自适应更新的。
            cx_pre = int(kalman_filter_x.return_predict())
            kalman_filter_y.kalman_adaptive(center[1])  # 设为0则是不使用自适应更新
            cy_pre = int(kalman_filter_y.return_predict())
            cv2.circle(frame, (cx_pre, cy_pre), r, (123, 0, 43), 2)
            # 在图片左上角显示图例说明
            cv2.putText(frame, "green: true position", (10, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            cv2.putText(frame, "purple: filter position", (10, 50),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.7, (123, 0, 43), 2)
            cv2.imshow("Not True", frame)
            if cv2.waitKey(30) & 0xFF == ord('q'):
                break
        else:
            break


if __name__ == '__main__':
    main()

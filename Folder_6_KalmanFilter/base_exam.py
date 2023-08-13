import math

import matplotlib.pyplot as plt
import numpy as np
from KalmanFilter import Kalman


def draw_lines(title, x, y1, y1_noise, y1_kalman):
    """绘制三条线"""
    plt.title(title)
    plt.plot(x, y1, label='y1')
    plt.plot(x, y1_noise, label='y1_noise')
    plt.plot(x, y1_kalman, label='y1_kalman')
    plt.legend()
    plt.show()


def base_exam():
    # 使用seaborn绘图
    # 1. 设定真值直线y1
    x = [i for i in range(300)]
    # y1与x个数相同
    y1 = [math.log10(0.001*(i+1)) for i in x]
    # 2. 对y1加入正态分布的噪声
    y1_noise = np.array(y1) + np.random.normal(0, 0.05, len(x))
    # 3. 对y1_noise进行卡尔曼滤波
    kalman_filter = Kalman()
    kalman_filter.get_args(r=10, q=0.1)
    # r是测量值的协方差，q是过程噪声的协方差
    # 如果要让卡尔曼滤波器快速收敛，可以将r设置为0，q设置为一个较大的值
    y1_kalman = []
    y2_kalman = []
    for item in y1_noise:
        kalman_filter.kalman_base(item)
        y1_kalman.append(kalman_filter.return_predict())
        kalman_filter.kalman_adaptive(item, update=1)

    # 4. 绘制y1, y1_noise, y1_kalman
    draw_lines("kalman_filter_base", x, y1, y1_noise, y1_kalman)


if __name__ == '__main__':
    base_exam()

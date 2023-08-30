import math
import matplotlib.pyplot as plt
import numpy as np
from KalmanFilter import Kalman


def draw_lines(x, y1, y1_noise, y1_kal, y2_kal):
    """绘制三条线"""
    plt.subplots(2, 1, sharex=True, sharey=True)
    # 选择上半部分绘制基本kalman滤波
    plt.subplot(2, 1, 1)
    plt.title("Kalman Filter Base")
    plt.plot(x, y1, label='y1')
    plt.plot(x, y1_noise, label='y1_noise')
    plt.plot(x, y1_kal, label='y1_kalman')
    plt.legend()
    # 选择下半部分绘制自适应kalman滤波
    plt.subplot(2, 1, 2)
    plt.title("Kalman Filter Adaptive")
    plt.plot(x, y1, label='y1')
    plt.plot(x, y1_noise, label='y1_noise')
    plt.plot(x, y2_kal, label='y2_kalman')
    plt.legend()
    plt.show()

def base_exam():
    # 使用seaborn绘图
    # 1. 设定真值直线y1
    x = [i for i in range(500)]
    # y1与x个数相同
    y1 = [5*math.sin(math.sin(2*math.radians(i))**5) for i in x]
    # 2. 对y1加入正态分布的噪声
    y1_noise = np.array(y1) + np.random.normal(0, 0.3, len(x))
    # 3. 对y1_noise进行卡尔曼滤波
    kalman_filter = Kalman()
    kalman_filter.get_args(r=1, q=0.1)
    # r是测量值的协方差，q是过程噪声的协方差
    # 如果要让卡尔曼滤波器快速收敛，可以将r设置为0，q设置为一个较大的值
    y1_kalman = []
    y2_kalman = []
    for item in y1_noise:
        kalman_filter.kalman_adaptive(item, update=0)
        y1_kalman.append(kalman_filter.return_predict())
    for item in y1_noise:
        kalman_filter.kalman_adaptive(item, update=1)
        y2_kalman.append(kalman_filter.return_predict())

    # 4. 绘制y1, y1_noise, y1_kalman
    draw_lines(x, y1, y1_noise, y1_kalman, y2_kalman)


if __name__ == '__main__':
    """
    可以从图像中看出，下半张图比上半张图的起点要更接近目标函数，或许是因为自适应参数更新使它波动减小了。
    """
    base_exam()

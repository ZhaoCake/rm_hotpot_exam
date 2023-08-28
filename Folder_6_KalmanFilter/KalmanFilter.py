import numpy as np


class Kalman:
    """单纯针对一维kalman filter的实现"""
    def __init__(self):
        self.y = 0  # 状态值
        self.p = 0  # 协方差
        self.p_m = 0  # 协方差计算中间值（更新）
        self.k = 0  # 卡尔曼增益
        self.r = 1  # 测量值的协方差
        self.q = 0.00001  # 过程噪声的协方差
        self.theta = np.zeros(2)  # 参数向量
        self.alpha = 1  # RLS算法的遗忘因子

    def get_args(self, r, q):
        """获取参数测量值、过程噪声协方差"""
        self.r = r
        self.q = q

    def return_predict(self):
        """返回当前状态值"""
        return self.y

    def kalman_base(self, measure):
        """Kalman filter"""
        self.p_m = self.p + self.q  # 更新协方差
        self.k = self.p_m / (self.p_m + self.r)  # 计算卡尔曼增益
        self.y = self.y + self.k * (measure - self.y)  # 更新状态值
        self.p = (1 - self.k) * self.p_m  # 更新协方差

    def kalman_adaptive(self, measure, update=1):
        """Adaptive Kalman filter"""
        # 基本的kalman filter
        self.kalman_base(measure)
        # 更新过程噪声和测量值的协方差
        if update == 1:
            # RLS算法的自适应参数更新，一种基于最小二乘法的自适应参数更新策略
            phi = np.array([measure, self.y])  # 参数向量
            error = measure - np.dot(self.theta, phi)  # 误差，
            p_phi = np.dot(self.p, phi)  # 协方差与参数向量的乘积
            denominator = self.alpha + np.dot(np.dot(phi.T, self.p), phi)  # 通过公式计算分母
            self.theta += np.dot(p_phi, error) / denominator  # 更新参数向量
            self.p -= np.dot(np.dot(p_phi, p_phi.T), self.p) / denominator  # 更新协方差
        elif update == 0:
            # 原始的kalman filter
            pass
        else:
            print("Argument \"update\" Not Implemented")
            exit(1)

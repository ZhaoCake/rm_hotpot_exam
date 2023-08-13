class Kalman:
    """单纯针对一维kalman filter的实现"""
    def __init__(self):
        self.y = 0  # 状态值
        self.p = 0  # 协方差
        self.p_m = 0  # 协方差计算中间值（更新）
        self.k = 0  # 卡尔曼增益
        self.r = 1  # 测量值的协方差
        self.q = 0.00001  # 过程噪声的协方差

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
            # 方差自适应更新q、r

            pass
        elif update == 2:
            # 卡方检验自适应更新q、r
            pass
        elif update == 3:
            # 残差自适应更新q、r
            pass
        else:
            print("Argument \"update\" Not Implemented")
            exit(1)
# 借鉴了[https://birdiebot.github.io/bubble_documentation/theory/RMUC2022%E5%A4%A7%E8%83%BD%E9%87%8F%E6%9C%BA%E5%85%B3%E9%A2%84%E6%B5%8B%E5%99%A8.html]的讲解，来修改了预测的部分
# 因为我之前采用的是对帧间进行差分算线速度，这在群内聊天中被指出是不对的，所以我进行了修改
import numpy as np
from scipy import signal


class Predict:
    """
    一个用于预测待击打扇叶1s后位置的类
    使用的时间单位是1/60s，即1帧
    """

    # 我要求我得到每一次的cen_arrow和obj_arrow，并且move_info列表也应该存在这个类里
    def __init__(self):
        """
        初始化一个用于预测待击打扇叶1s后位置的类
        """
        self.cen_angle = None  # 我应该使用这个值来进行角速度、波峰波谷的计算
        self.obj_angle = None
        self.cen_data = []
        self.state = 0  # 0表示继续获取数据，1表示停止获取数据
        self.sign_state = 0  # 0表示不做处理，1表示进行反向处理
        self.orientation = None  # 旋转方向
        self.angle_velocity_list = []  # 角速度
        self.func = None  # 角速度函数
        self.predict_angle = None  # 预测角度

    def predict(self):
        self.get_cen_data()
        if len(self.angle_velocity_list) >= 100:
            """
            寻找波峰波谷，主要是波谷，两个，得到周期，再有波峰，可得振幅和偏置，那么函数就有了
            """
            peak_value = 0
            trough_value = 0
            period_list = []
            peak_index = self.find_peak(np.array(self.angle_velocity_list),
                                        0.09)
            for i in range(len(peak_index)):
                peak_value += self.angle_velocity_list[peak_index[i]]
                # 计算peak_index的两两之差，加入period列表
                if i != 0:
                    period_list.append(peak_index[i] - peak_index[i - 1])
            try:
                peak_value = peak_value / len(peak_index)
            except ZeroDivisionError:
                peak_value = None
            trough_index = self.findTrough(np.array(self.angle_velocity_list),
                                           0.09)  # 其实这里的是没有用的，因为没有必要，干扰不大
            for i in range(len(trough_index)):
                trough_value += self.angle_velocity_list[trough_index[i]]
                if i != 0:
                    period_list.append(trough_index[i] - trough_index[i - 1])
            try:
                trough_value = trough_value / len(trough_index)
            except ZeroDivisionError:
                trough_value = None
            period = None
            if len(period_list) != 0:
                period = np.mean(period_list)
                # print("period:", period)
            period = 201  # 计算得出的周期有些大，所以我直接给了一个固定值，但是如果需要的话，可以注释掉这一行来看看我的效果
            if trough_value is not None and peak_value is not None and period is not None:
                a = (peak_value - trough_value) / 2
                b = (trough_value + peak_value) / 2
                omiga = 2 * np.pi / period
                """
                得到一个目标函数，这个函数是角速度关于帧数的函数
                """

                # a = 0.040201594897572156
                # b = 0.06054993193418074
                def func1(add_value=0):
                    # x 是get_now_frame()的返回值整除2pi的余数
                    x = (get_now_frame() + add_value) % period
                    # print("x:", x)
                    return a * np.cos(
                        omiga * x) + b  # 使用cos,这样从波峰开始，对计算当前值更加友好

                def get_now_frame():
                    """
                    获取当前帧数
                    """
                    return len(self.angle_velocity_list) - peak_index[0]

                def func1_30():
                    delta_angle = 0
                    for i in range(20):
                        delta_angle += func1(i)
                    return delta_angle

                self.func = func1_30
        else:
            pass

        # 如果func不为空，那么就进行预测
        if self.func is not None:
            if self.obj_angle is not None:
                self.predict_angle = self.obj_angle + self.func()

    def cvt_angle(self, arrow: tuple) -> float:
        """
        将矢量转化为弧度数
        """
        try:
            angle = np.arctan(arrow[1] / arrow[0])
            if arrow[0] < 0:
                angle += np.pi
            if angle < 0:
                angle += 2 * np.pi
        except TypeError:
            angle = None
        except ZeroDivisionError:
            angle = np.pi / 2
        return angle

    def read_cen(self, cen_arrow: tuple):
        """
        读取圆心的矢量，判断是否反向
        """
        crt_cen_angle = self.cvt_angle(cen_arrow)
        if crt_cen_angle is not None:
            if self.cen_angle is not None:
                # print("cen_angle is not None")
                # 比较两个角度的大小，如果相差大于pi，则将crt_cen_angle加上pi
                if abs(crt_cen_angle - self.cen_angle) > 1.55:
                    # print("can judge sign")
                    self.sign_state = 1
                else:
                    self.sign_state = 0
                if not self.sign_state:
                    # print("can accept yuan")
                    cen_angle = crt_cen_angle
                else:
                    # print("can accept bian")
                    mid_cen_angle = crt_cen_angle + np.pi
                    if mid_cen_angle > 2 * np.pi:
                        mid_cen_angle -= 2 * np.pi
                    cen_angle = mid_cen_angle
                return cen_angle
            else:
                # print("cen_angle is None")
                cen_angle = crt_cen_angle
                return cen_angle

    # def print_cen(self):
    #     print("cen_angle:", self.cen_angle)

    def get_cen_data(self):
        """当cen_arrow不再为零时，将其添加到cen_data中"""
        # print("cen_angle:", self.cen_angle)
        cen_angle = self.cen_angle
        if cen_angle is not None:
            self.cen_data.append(cen_angle)
        # print("cen_data:", self.cen_data)
        # 如果cen_data的最后两个是非空的，那么就计算角速度
        # print(self.cen_data)
        if len(self.cen_data) > 10:
            self.judge_direction_rotation()
            if self.cen_data[-1] is not None and self.cen_data[-3] is not None:
                angular_velocity = self.cal_angular_velocity(
                    self.cen_data[-3], self.cen_data[-1])
                # print("角速度为：", angular_velocity)
                self.angle_velocity_list.append(angular_velocity)
                # print("angle_velocity_list:", self.angle_velocity_list)
                if len(self.angle_velocity_list) > 20:
                    self.pre_process_angle_vel()
                    # self.front_2pi[cen_angle] = self.angle_velocity_list[-1]

    def judge_direction_rotation(self):
        interpolation_num = 2
        # 只取列表的最后一百个，如果不够一百个，就取全部
        if len(self.cen_data) > 100:
            data_array = np.array(self.cen_data[-100:])
        else:
            data_array = np.array(self.cen_data)
        # data_array = np.array(self.cen_data)
        data_array[data_array < 0] += 2 * np.pi
        dup_degree_list = list(
            data_array)  # 借鉴的开源代码这里用了深拷贝，但是我不知道为什么，就照自己的习惯写了。
        for i in range(interpolation_num):
            dup_degree_list.insert(0, 0)
        dup_degree_array = np.array(dup_degree_list)
        # 干（方言，相间）一个相减
        sub = np.subtract(data_array, dup_degree_array[:-interpolation_num])
        # 按照0的比例来确定旋转方向
        ratio = np.count_nonzero(sub > 0) / len(self.cen_data)
        if ratio < 0.5:
            self.orientation = "positive"  # 顺时针
        elif ratio >= 0.5:
            self.orientation = "negative"  # 逆时针

    def cal_angular_velocity(self, last_rad: float, cur_rad: float) -> float:
        radian_differ = cur_rad - last_rad  # 单帧的弧度差，也就是我以一帧为一个时间单位的角速度
        return radian_differ

    def pre_process_angle_vel(self):
        """
        对于angle_list，先进行预处理，这些可以直接迁移到Predict类中
        下一步：取出前面400帧左右，找到波峰和波谷，然后根据波峰和波谷的位置，计算出周期、振幅、偏置，得到角速度的函数
            对角速度函数进行积分，得到关于位置的角度函数
            也就是说，要将前面的angle_velocity_list与cen_angle_list结合起来，然后再进行处理
            注：在这个视频中，找波谷会更快一些，但是在实际中肯定是两个都要写哒。
        """
        # 预处理
        # 1.去除空值
        angle_velocity_list = np.array(self.angle_velocity_list)
        angle_velocity_list = angle_velocity_list[angle_velocity_list != None]
        # 2.去除异常值
        angle_velocity_list = angle_velocity_list[angle_velocity_list < 0.2]
        # 3.把非正值改为前一个值
        for i in range(len(angle_velocity_list)):
            if angle_velocity_list[i] <= 0 or angle_velocity_list[i] >= 0.2:
                angle_velocity_list[i] = angle_velocity_list[i - 1]
        # 不改变数据分布，但是平滑
        angle_velocity_list = signal.savgol_filter(angle_velocity_list, 9,
                                                   3)  # 参数作用：5是窗口大小，3是多项式的阶数
        # 4.去除偏置
        # angle_velocity_list = angle_velocity_list - np.mean(angle_velocity_list)
        # 5.去除振幅
        # angle_velocity_list = angle_velocity_list / np.max(angle_velocity_list)
        self.angle_velocity_list = list(angle_velocity_list)

    def find_peak(self, data_array: np.ndarray, thres: float):
        """
        找到角速度图像的波峰和波谷
        只需要取前面200帧左右的数据即可
        """
        # print("进入函数")
        peaks_index_list, peaks_dict = signal.find_peaks(data_array,
                                                         height=thres,
                                                         distance=190)
        # # distance用于确定两个波峰的最小距离, 虽然索引是用的cen_angle，但是在这里可体现不出来
        # print(peaks_index_list)
        # print(peaks_dict)
        # print("找到波峰")
        # if len(peaks_index_list) != 0:
        #     peak_index = np.argmax(peaks_dict["peak_heights"])  # peak_heights是一个数组，里面存放的是波峰的高度
        #     if 200 <= peak_index or peak_index <= len(data_array) - 200:
        #         peak_index = None  # 毕竟用cen_angle来索引的话，这个判断它没法弄啊。
        # time.sleep(2)
        return peaks_index_list

    def findTrough(self, data_array: np.ndarray, thres: float):
        # trough_index = None
        negative_data_array = np.negative(data_array)  # 数组取相反数
        troughs_index_list, _ = signal.find_peaks(negative_data_array,
                                                  distance=190)
        # print("找到波谷")
        # print(troughs_index_list)
        # time.sleep(2)
        # print(troughs_dict)
        # if len(troughs_index_list) != 0:
        #     trough_index = np.argmin(troughs_dict["peak_heights"])
        #     if 190 >= trough_index or trough_index >= len(data_array) - 190:
        #         trough_index = None
        # trough_index = troughs_index_list
        return troughs_index_list

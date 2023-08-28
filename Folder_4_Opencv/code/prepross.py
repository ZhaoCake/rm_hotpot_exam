import cv2
import numpy as np
import traceback


def get_contours(src_img):
    """获取图像中的轮廓"""
    # 二值化
    gray = cv2.cvtColor(src_img, cv2.COLOR_BGR2GRAY)
    # cv2.imshow("gray_window", gray)
    ret, mask = cv2.threshold(gray, 100, 255, cv2.THRESH_BINARY, cv2.THRESH_OTSU)
    # 先膨胀后腐蚀，避免边缘断裂
    kernel = np.ones((11, 11), np.uint8)
    mask = cv2.dilate(mask, kernel)
    mask = cv2.erode(mask, kernel)
    # 轮廓提取
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    # 计算轮廓面积
    areas = []
    for contour in contours:
        areas.append(cv2.contourArea(contour))
    return contours, areas


class PreProcess:
    """因为画面是基本固定的，所以其实可以把画面分成几块来降低难度"""
    def __init__(self):
        self.img = None
        # self.draw_img = None # 用于绘制的图像
        self.center = None
        self.cx = 0
        self.cy = 0
        self.cen_arrow = None
        self.obj_arrow = None
        self.pred_box = None
        self.obj_chang = 0
        self.obj_kuan = 0
        self.obj_distance = 0

    def return_circle_heart(self):
        return self.cx, self.cy

    def get_img(self, frame):
        self.img = frame
        # self.draw_img = frame.copy()
        # 对图像左右百分之20赋值为0
        height, width = self.img.shape[:2]
        self.img[:, 0:int(width * 0.3)] = 0
        self.img[:, int(width * 0.7):width] = 0
        # 将图像中心10%复制到center中
        self.center = self.img[int(height * 0.44):int(height * 0.51), int(width * 0.48):int(width * 0.52)]

    def find_cen_arrow(self, box):
        """
        从最小矩形中，以长边的方向找到一个矢量
        矢量的方向不好确定，可以只考虑半圈，圆心的上半部分
        这样就是每转两个半圈为一个周期
        """
        chang = np.linalg.norm(box[0] - box[1])
        kuan = np.linalg.norm(box[1] - box[2])
        if chang > kuan:
            self.cen_arrow = box[0] - box[1]
        else:
            self.cen_arrow = box[1] - box[2]
        # 矢量归一化，乘以100
        self.cen_arrow = self.cen_arrow / np.linalg.norm(self.cen_arrow) * 100

    def new_find_cen_arrow(self, arrow):
        try:
            # 矢量平移到圆心
            arrow = np.intp(arrow + np.array([self.cx, self.cy]))
            # 画出矢量
            # cv2.line(self.draw_img, (self.cx, self.cy), (arrow[0], arrow[1]), (21, 43, 234), 3)
            # print("矢量已画出")
        except ValueError as e:
            # 原因是闪光期间，箭头有在飘动
            print(e.args)
            print("======")
            print(traceback.format_exc())
        except TypeError as e:
            print(e.args)
            print("======")
            print(traceback.format_exc())

    def get_circle_heart(self):
        """获取图像中的轮廓"""
        # 二值化
        contours, areas = get_contours(self.center)
        try:
            # 找出最大轮廓
            max_area = max(areas)
            max_index = areas.index(max_area)
            # 找出最大轮廓外接矩形
            rect = cv2.minAreaRect(contours[max_index])
            box = cv2.boxPoints(rect)
            # 找出圆心
            self.cx = int(rect[0][0])
            self.cy = int(rect[0][1])
            # 变换圆心坐标
            self.cx += int(self.img.shape[1] * 0.48)
            self.cy += int(self.img.shape[0] * 0.44)
            try:
                self.find_cen_arrow(box)
            except ValueError:
                print("没有找到矢量")
            box = np.intp(box)
            # 将坐标转换到原图中
            box[:, 0] += int(self.img.shape[1] * 0.48)
            box[:, 1] += int(self.img.shape[0] * 0.44)
            # 画出外接矩形
            # cv2.drawContours(self.draw_img, [box], 0, (0, 123, 231), 3)
        except ValueError:
            # print("没有找到轮廓")
            pass

    def get_obj_arrow(self, box):
        """比较相邻边的大小，找到短边求出短边中点，圆心到中点的矢量"""
        # 相邻边的长度
        chang = np.linalg.norm(box[0] - box[1])
        kuan = np.linalg.norm(box[1] - box[2])
        if chang > kuan:
            # 短边中点
            end = (box[1] + box[2]) / 2
        else:
            end = (box[0] + box[1]) / 2
        # 圆心到中点的矢量
        self.obj_arrow = end - np.array([self.cx, self.cy])
        # 矢量归一化，乘以100
        self.obj_arrow = self.obj_arrow / np.linalg.norm(self.obj_arrow) * 100
        # 提示
        # print("矢量已求出")

    def get_object(self):
        """获取图像中的轮廓"""
        contours, areas = get_contours(self.img)
        try:
            # 找出面积大于100中的轮廓里面面积最小的轮廓
            min_area = min([area for area in areas if area > 10000])
            min_index = areas.index(min_area)
            rect = cv2.minAreaRect(contours[min_index])
            box = cv2.boxPoints(rect)
            box = np.intp(box)
            self.obj_chang = rect[1][0]
            self.obj_kuan = rect[1][1]
            self.obj_distance = np.linalg.norm(rect[0] - np.array([self.cx, self.cy]))
            # 找出矢量
            self.get_obj_arrow(box)
            # 将box表示的矩形中的部分旋转后拷贝到h_obj中
            # 画出最小外接矩形
            # cv2.drawContours(self.draw_img, [box], 0, (0, 255, 0), 2)
        except ValueError:
            # print("没有找到第二个轮廓")
            pass

    def process_img(self, src):
        """调用函数，返回处理后的信息"""
        self.get_img(src)
        self.get_circle_heart()
        self.get_object()
        return self.cen_arrow, self.obj_arrow

    def return_heart(self):
        """返回圆心坐标"""
        return self.cx, self.cy

    def draw_obj(self, theta: float):
        """
        根据外面预测的方向点，画出预测的矩形框
        :param theta: 预测的角度
        """
        # 先把角度在四个象限转化成需要的角度
        # 矩形中心，这个函数的theta要用弧度，所以放在前面
        obj_center = np.array([np.cos(theta), np.sin(theta)]) * self.obj_distance + np.array([self.cx, self.cy])
        # 使两边中长的那条与theta平行
        if self.obj_chang > self.obj_kuan:
            self.obj_kuan, self.obj_chang = self.obj_chang, self.obj_kuan
        # 先把弧度转为角度
        theta = theta / np.pi * 180
        # 当theta在第一象限时，不需要转化
        if 0 <= theta <= 90:
            self.obj_chang, self.obj_kuan = self.obj_kuan, self.obj_chang
        # 当theta在第二象限时，需要减去90
        elif 90 < theta <= 180:
            theta -= 90
        # 当theta在第三象限时，需要减去180
        elif 180 < theta < 270:
            theta -= 180
            self.obj_chang, self.obj_kuan = self.obj_kuan, self.obj_chang
        # 当theta在第四象限时，需要减去270
        elif 270 <= theta < 360:
            theta -= 270

        # 得到rotaterect
        rect = ((obj_center[0], obj_center[1]), (self.obj_chang, self.obj_kuan), theta)
        box = cv2.boxPoints(rect)
        self.pred_box = np.intp(box)
        # 画出最小外接矩形
        # cv2.drawContours(self.draw_img, [self.pred_box], 0, (0, 12, 231), 2)


if __name__ == '__main__':
    # 对模块单独测试
    img = cv2.imread("src/imgs/blue_dark_300.png")
    pre_er = PreProcess()
    pre_er.get_img(img)
    pre_er.get_circle_heart()
    pre_er.get_object()
    # pre_er.process_h_obj()

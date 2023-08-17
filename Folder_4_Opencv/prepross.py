import cv2
import numpy as np


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
        self.center = None
        self.cx = 0
        self.cy = 0
        self.cen_arrow = None
        self.obj_arrow = None
        # self.h_obj = None  # 暂时没用

    def return_circle_heart(self):
        return self.cx, self.cy

    def get_img(self, frame):
        self.img = frame
        # 对图像左右百分之20赋值为0
        height, width = self.img.shape[:2]
        self.img[:, 0:int(width * 0.3)] = 0
        self.img[:, int(width * 0.7):width] = 0
        # 将图像中心10%复制到center中
        self.center = self.img[int(height * 0.44):int(height * 0.51), int(width * 0.48):int(width * 0.52)]
        # cv2.imshow("center_window", self.center)
        # cv2.imshow("img_window", self.img)
        # cv2.waitKey(0)

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

        # print(self.arrow)

    def new_find_cen_arrow(self, arrow):
        try:
            # 矢量平移到圆心
            arrow = np.intp(arrow + np.array([self.cx, self.cy]))
            # 画出矢量
            cv2.line(self.img, (self.cx, self.cy), (arrow[0], arrow[1]), (21, 43, 234), 3)
            # print("矢量已画出")
        except:
            # 原因是闪光期间，箭头有在飘动
            print("矢量画出失败")

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
            cv2.drawContours(self.img, [box], 0, (0, 123, 231), 3)
        except ValueError:
            # print("没有找到轮廓")
            pass
    # def process_h_obj(self):  # 如果没有必要找到前面的装甲板的击打区域的话，这个函数可以不用
    #     """对h_obj进行处理"""
    #     # 二值化反转
    #     gray = cv2.cvtColor(self.h_obj, cv2.COLOR_BGR2GRAY)
    #     ret, mask = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV, cv2.THRESH_OTSU)
    #     # 查找最小白色轮廓
    #     contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    #     areas = []
    #     for contour in contours:
    #         areas.append(cv2.contourArea(contour))
    #     min_area = min(areas)
    #     min_index = areas.index(min_area)
    #     # 找出最小轮廓外接矩形
    #     rect = cv2.minAreaRect(contours[min_index])
    #     box = cv2.boxPoints(rect)
    #     box = np.intp(box)
    #     # 画出最小外接矩形
    #     cv2.drawContours(self.h_obj, [box], 0, (0, 123, 231), 3)
        # cv2.imshow("mask_window", mask)
        # cv2.waitKey(0)

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
            # 找出第二小轮廓最小外接矩形
            rect = cv2.minAreaRect(contours[min_index])
            box = cv2.boxPoints(rect)
            box = np.intp(box)
            # 找出矢量
            self.get_obj_arrow(box)
            # 将box表示的矩形中的部分旋转后拷贝到h_obj中
            # 画出最小外接矩形
            cv2.drawContours(self.img, [box], 0, (0, 255, 0), 2)
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


if __name__ == '__main__':
    # 对模块单独测试
    img = cv2.imread("src/imgs/blue_dark_300.png")
    pre_er = PreProcess()
    pre_er.get_img(img)
    pre_er.get_circle_heart()
    pre_er.get_object()
    # pre_er.process_h_obj()

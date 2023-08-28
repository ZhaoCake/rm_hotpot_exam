import numpy as np
import cv2
from prepross import PreProcess
from predict import Predict
import time
import traceback


def rotate_arrow(arrow, rad):
    """
    旋转矢量
    :param arrow: 矢量
    :param rad: 旋转角度
    :return: 旋转后的矢量
    """
    # 将arrow绕原点旋转rad角度
    rotate_matrix = np.array([[np.cos(rad), -np.sin(rad)],
                              [np.sin(rad), np.cos(rad)]])
    return np.dot(rotate_matrix, arrow)


def main():
    """
    一个python的实现，具体的思路在README.md中。
    """
    path = "../video/blue_dark.mp4"
    pre_hand = PreProcess()
    predict = Predict()
    cap = cv2.VideoCapture(path)
    log = time.strftime("%Y%m%d%H%M%S", time.localtime()) + ".txt"
    while cap.isOpened():
        start = time.time()
        ret, frame = cap.read()
        if not ret:
            break
        cen_arrow, obj_arrow = pre_hand.process_img(frame)
        # 反转并计算距离，距离小的为当前的cen_arrow，其实借鉴了一点kf的思想
        try:
            t_cen_arrow = tuple(cen_arrow)
            t_obj_arrow = tuple(obj_arrow)
            predict.cen_angle = predict.read_cen(t_cen_arrow)
            # print("cen_angle:", predict.cen_angle)
            predict.obj_angle = predict.cvt_angle(t_obj_arrow)
            # predict.print_cen()
            # if predict.state == 0:
            predict.predict()
            # 画一下 predict.predict_angle
            # print("不会被答应")
        # 处理异常并且对其进行处理，输出发生的错误
        except TypeError as e:
            print(e.args)
            print("======")
            print(traceback.format_exc())
        try:
            # 返回圆心坐标
            cx, cy = pre_hand.return_circle_heart()
            # 先把obj_angle的转为直角坐标
            obj_angle_arrow = np.array(
                [np.cos(predict.obj_angle),
                 np.sin(predict.obj_angle)]) * 100 + np.array([cx, cy])
            # 画出
            # cv2.line(pre_hand.draw_img, (int(cx), int(cy)), (int(obj_angle_arrow[0]), int(obj_angle_arrow[1])), (255, 0, 0), 2)

            # 画一下 圆心到 predict.predict_angle，如果不是None的话
            if predict.predict_angle is not None:
                # predict_angle是一个角度，需要画出以cx, cy为圆心的这个矢量
                # 将predict.predict_angle从极坐标系转换到笛卡尔坐标系，圆心为cx, cy，长度为100
                # 超过2pi的部分，需要减去2pi
                if predict.predict_angle > 2 * np.pi:
                    predict.predict_angle -= 2 * np.pi
                predict_arrow = np.array([
                    np.cos(predict.predict_angle),
                    np.sin(predict.predict_angle)
                ]) * 100
                pre_hand.draw_obj(predict.predict_angle)
                # 将predict_arrow的圆心坐标设为cx, cy
                # predict_arrow = predict_arrow + np.array([cx, cy])
                # try:
                #     # 画出从圆心到predict_arrow的直线
                #     cv2.line(pre_hand.draw_img, (int(cx), int(cy)), (int(predict_arrow[0]), int(predict_arrow[1])), (0, 255, 0), 3)
                #     # 将predict_angle的值输出到图像上
                #     cv2.putText(pre_hand.draw_img, str(predict.predict_angle), (int(cx), int(cy)), cv2.FONT_HERSHEY_SIMPLEX, 1,
                #                 (255, 255, 255), 2)
                #     # 从目前多次尝试的结果来看，这也只能是cen_arrow的问题了
                # except ValueError as e:
                #     print(e.args)
                #     print("======")
                #     print(traceback.format_exc())
        except TypeError as e:
            print(e.args)
            print("======")
            print(traceback.format_exc())
        # 将pre_hand.pred_box转为列表
        pre_box = None
        if pre_hand.pred_box is not None:
            pre_box = list(pre_hand.pred_box)
        end = time.time()
        # 对delta_time保留八位小数
        delta_time = round((end - start) * 1000, 8)

        print("\ttime:", delta_time, "ms", "\tpredict_box:", f"{pre_box}",
              "\torientation:", predict.orientation)
        # 将上述输出写入日志文件,名称是日期加时间的純数字形式
        with open(log, "a") as f:
            f.write("\ttime:" + str(delta_time) + "ms" + "\tpredict_box:" +
                    str(pre_box) + "\torientation:" +
                    str(predict.orientation) + "\n")
        # cv2.imshow("test_window", pre_hand.draw_img)
        # if cv2.waitKey(1) & 0xFF == ord('q'):
        #     break
    cap.release()
    cv2.destroyAllWindows()
    # 画角速度关于帧数的图像
    # print(predict.angle_velocity_list)
    # angle_list = list(predict.angle_velocity_list)
    # # print(angle_list)
    # if len(angle_list) > 1:
    #     # 将从1开始的正整数和angle_list结合为一个DataFrame
    #     df = pd.DataFrame({"frame": range(1, len(angle_list) + 1), "angle": angle_list})
    #     # 画angle_list的折线图，横坐标是从1开始的正整数，纵坐标是angle_list
    #     plt = df.plot(x="frame", y="angle", kind="line")
    #     # 设置横坐标的标签
    #     plt.set_xlabel("frame")
    #     # 设置纵坐标的标签
    #     plt.set_ylabel("angle")
    #     # 设置标题
    #     plt.set_title("angle")
    #     # 设置画布的大小
    #     plt.get_figure().set_size_inches(12, 4)
    #     # 保存图片
    #     plt.get_figure().savefig("angle_gan3.png")

    # 画出predict.func的图像
    # 将从1开始到2000的正整数和predict.func结合为一个DataFrame
    # def funca(x):
    #     return 0.040201594897572156 * np.cos(2 * np.pi / 201 * x) + 0.06054993193418074
    # df = pd.DataFrame({"frame": range(1, 2001), "angle": [funca(i) for i in range(1, 2001)]})
    # # 画predict.func的折线图，横坐标是从1开始的正整数，纵坐标是predict.func
    # plt = df.plot(x="frame", y="angle", kind="line")
    # # 设置横坐标的标签
    # plt.set_xlabel("frame")
    # # 设置纵坐标的标签
    # plt.set_ylabel("angle")
    # # 设置标题
    # plt.set_title("angle")
    # # 设置画布的大小
    # plt.get_figure().set_size_inches(12, 4)
    # # 保存图片
    # plt.get_figure().savefig("func.png")


if __name__ == '__main__':
    main()

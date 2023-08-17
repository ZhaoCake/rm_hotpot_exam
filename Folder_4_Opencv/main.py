import numpy as np
import pandas as pd
import cv2
from prepross import PreProcess
import time


def rotate_arrow(arrow, rad):
    """
    旋转矢量
    :param arrow: 矢量
    :param rad: 旋转角度
    :return: 旋转后的矢量
    """
    # 将arrow绕原点旋转rad角度
    rotate_matrix = np.array([[np.cos(rad), -np.sin(rad)], [np.sin(rad), np.cos(rad)]])
    return np.dot(rotate_matrix, arrow)

def main():
    """
    一个python的实现，具体的思路在README.md中。
    """
    path = "src/blue_dark.mp4"
    pre_hand = PreProcess()
    cap = cv2.VideoCapture(path)
    move_info = []
    while cap.isOpened():
        start = time.time()
        ret, frame = cap.read()
        if not ret:
            break
        cen_arrow, obj_arrow = pre_hand.process_img(frame)
        # 反转并计算距离，距离小的为当前的cen_arrow，其实借鉴了一点kf的思想
        try:
            if move_info[-1][1] is not None:
                inv_cen_arrow = -cen_arrow
                # 比较inv_cen_arrow和cen_arrow关于上一个cen_arrow的距离
                cen_arrow_diff = np.linalg.norm(cen_arrow - move_info[-1][1])
                inv_arrow_diff = np.linalg.norm(inv_cen_arrow - move_info[-1][1])
                print(cen_arrow_diff, inv_arrow_diff)
                # 如果inv_cen_arrow和cen_arrow的距离小于cen_arrow和上一个cen_arrow的距离，则将cen_arrow置为inv_cen_arrow
                if inv_arrow_diff < cen_arrow_diff:
                    cen_arrow = inv_cen_arrow
                pre_hand.new_find_cen_arrow(cen_arrow)
        except IndexError:
            pass
        # 找出一个周期，一个周期的标志是cen_arrow的自身出现过的距离达到最小值
        try:
            # 如果当前move_info的倒数第二个元素不为空，则计算当前cen_arrow和倒数第二个元素的cen_arrow的每个分量的差值
            if move_info and move_info[-2][1] is not None:
                cen_arrow_diff = np.linalg.norm(cen_arrow - move_info[-2][1])
                speed = cen_arrow_diff * 30  # 每秒线速度
                if speed > 400:
                    speed = None  # 如果速度大于500，说明是异常值，将其置为None
            else:
                speed = None
        except IndexError:
            speed = None  # 由于索引倒数第二个元素导致的
        # 将当前帧数、cen_arrow、obj_arrow、speed包装成一个list，存入move_info中
        move_info.append([cap.get(cv2.CAP_PROP_POS_FRAMES), cen_arrow, obj_arrow, speed])
        # 平滑后的速度字典当成函数来用
        try:
            # 当move_info的长度大于等于60时，才进行拟合
            if len(move_info) == 330:
                # 是否进入了
                print("ok")
                # 取出106帧到329帧的数据
                speed_data = move_info[106:329]
                # 取出106帧到329帧的speed
                speed_data = [i[3] for i in speed_data]
                # 删除speed_data中的None
                speed_data = [i for i in speed_data if i is not None]
                x_data = np.arange(len(speed_data))
                # 平滑处理
                speed_data = pd.Series(speed_data).rolling(50, min_periods=1).mean()
                # 画出拟合的曲线
                plt = pd.DataFrame({"frame": x_data, "speed": speed_data}).plot(x="frame", y="speed", kind="line")
                plt.set_xlabel("frame")
                plt.set_ylabel("speed")
                plt.set_title("speed")
                # 画布的大小
                plt.get_figure().set_size_inches(12, 4)
                # 保存图片
                plt.get_figure().savefig("src/speed_fit_2.png")
                # 将speed_data转成字典，索引为从零开始的整数
                speed_dict = dict(zip(np.arange(len(speed_data)), speed_data))
                # 存储csv
                pd.DataFrame(speed_dict, index=[0]).to_csv("src/speed_dict.csv")
        except RuntimeError:
            pass
        # 获取当前帧数
        frame_num = cap.get(cv2.CAP_PROP_POS_FRAMES)
        # 如果speed_dict不为空，则计算与当前速度差最小的帧数
        # 如果不存在speed_dict这个变量，则令这个变量为None
        try:
            speed_dict
        except NameError:
            speed_dict = None
        # print(speed_dict)
        x_diff = 0
        if speed_dict:
            try:
                speed_diff = [abs(speed_dict[i] - speed) for i in range(len(speed_dict))]
                # 找到速度差最小和倒数第二小的帧数
                min_index = speed_diff.index(min(speed_diff))
                speed_diff[min_index] = 10000
                min_index_2 = speed_diff.index(min(speed_diff))
                # 找到字典中的极大值对应的帧数
                max_index = [i for i in speed_dict.keys() if speed_dict[i] == max(speed_dict.values())][0]
                # 读取move_info中的最后6帧的速度，判断在加速还是减速
                speed_1 = move_info[-1][3]
                speed_2 = move_info[-2][3]
                speed_3 = move_info[-3][3]
                speed_4 = move_info[-4][3]
                speed_5 = move_info[-5][3]
                speed_6 = move_info[-6][3]
                speed_avg = (speed_1 + speed_2 + speed_3 + speed_4 + speed_5 + speed_6) / 3
                # 如果当前速度大于平均速度，则说明是加速，否则是减速
                if speed > speed_avg:
                    # 是加速，在字典中max_index的前面去定位当前帧数
                    # 判断min_index和min_index_2哪个在0-max_index之间
                    if min_index < max_index:
                        # 如果min_index在0-max_index之间
                        # 从min_index开始，速度/60，一直相加到60帧以后
                        for i in range(min_index, min_index + 60):
                            if i > len(speed_dict) - 1:
                                x_diff += speed_dict[i - len(speed_dict)] / 60
                            else:
                                x_diff += speed_dict[i] / 60
                    else:
                        # 如果min_index_2在0-max_index之间
                        # 从min_index_2开始，速度/60，一直相加到60帧以后
                        for i in range(min_index_2, min_index_2 + 60):
                            if i > len(speed_dict) - 1:
                                x_diff += speed_dict[i - len(speed_dict)] / 60
                            else:
                                x_diff += speed_dict[i] / 60
                else:
                    # 是减速，在字典中max_index的后面去定位当前帧数
                    # 判断min_index和min_index_2哪个在max_index-最后一帧之间
                    if min_index > max_index:
                        # 如果min_index在max_index-最后一帧之间
                        # 从min_index开始，速度/60，一直相加到60帧以后，超出的部分再从0开始
                        for i in range(min_index, min_index + 60):
                            if i > len(speed_dict) - 1:
                                x_diff += speed_dict[i - len(speed_dict)] / 60
                            else:
                                x_diff += speed_dict[i] / 60
                    else:
                        # 如果min_index_2在max_index-最后一帧之间
                        # 从min_index_2开始，速度/60，一直相加到60帧以后，超出的部分再从0开始
                        for i in range(min_index_2, min_index_2 + 60):
                            if i > len(speed_dict) - 1:
                                x_diff += speed_dict[i - len(speed_dict)] / 60
                            else:
                                x_diff += speed_dict[i] / 60
            except ValueError:
                pass
            except TypeError:
                pass
            # 得到弧度
            rad = x_diff / 100
            # 将obj_arrow顺时针旋转rad角度，得到pre_arrow
            pre_arrow = rotate_arrow(obj_arrow, rad)
            # 返回圆心坐标
            cx, cy = pre_hand.return_circle_heart()
            # 将pre_arrow的圆心坐标设为cx, cy
            pre_arrow = pre_arrow + np.array([cx, cy])
            # 画出从圆心到pre_arrow的直线
            cv2.line(frame, (int(cx), int(cy)), (int(pre_arrow[0]), int(pre_arrow[1])), (0, 0, 255), 2)
        end = time.time()
        # 单位ms
        print("time: ", (end - start) * 1000, "ms", "frame: ", frame_num, "speed: ", speed, "x_diff: ", x_diff, end="\r")
        # 输出存入日志文件
        with open("log.txt", "a") as f:
            f.write("time: " + str((end - start) * 1000) + "ms" + " frame: " + str(frame_num) + " speed: " + str(speed) + " x_diff: " + str(x_diff) + "\n")
        cv2.imshow("test_window", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    cap.release()
    cv2.destroyAllWindows()
    # 将move_info转换为DataFrame
    move_info = pd.DataFrame(move_info, columns=["frame", "cen_arrow", "obj_arrow", "speed"])
    # 平滑处理，如果需要未经平滑处理的图像，可以注释掉下面这行代码
    move_info["speed"] = move_info["speed"].rolling(10, min_periods=1).mean()
    # 画出speed关于frame的折线统计图
    plt = move_info.plot(x="frame", y="speed", kind="line")
    plt.set_xlabel("frame")
    plt.set_ylabel("speed")
    plt.set_title("speed")
    # 画布的大小
    plt.get_figure().set_size_inches(12, 4)
    # 保存图片
    plt.get_figure().savefig("src/speed.png")
    # 写入csv文件
    move_info.to_csv("src/move_info.csv", index=False)


if __name__ == '__main__':
    main()

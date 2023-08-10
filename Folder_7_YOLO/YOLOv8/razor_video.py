# 一个用于压缩avi视频的脚本

import cv2

# 读入视频
video = cv2.VideoCapture('test_video.avi')

# 获取视频的fps，width，height
fps = video.get(cv2.CAP_PROP_FPS)
width = int(video.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(video.get(cv2.CAP_PROP_FRAME_HEIGHT))

# 设置压缩格式，压缩为MP4
fourcc = cv2.VideoWriter_fourcc(*'mp4v')

# 设置输出视频的参数，分别为视频名，编码格式，帧率，视频宽高
out = cv2.VideoWriter('test2.mp4', fourcc, fps, (width, height))

# 读取视频的每一帧，然后写入输出视频
while True:
    ret, frame = video.read()
    if ret:
        out.write(frame)
    else:
        break

# 释放资源
video.release()
out.release()
cv2.destroyAllWindows()

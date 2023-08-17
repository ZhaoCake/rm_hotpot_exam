import cv2

# 读出视频的300到305帧并保存

path = "blue_light.mp4"
cap = cv2.VideoCapture(path)
count = 0
while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break
    count += 1
    if count >= 300 and count <= 305:
        cv2.imwrite("imgs/blue_light_{}.png".format(count), frame)
    if count > 305:
        break
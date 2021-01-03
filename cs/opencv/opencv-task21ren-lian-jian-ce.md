---
title: ' OpenCV Task21：人脸检测'
date: 2019-07-09 22:08:59
tags: [OpenCV]
published: true
hideInList: false
feature: /post-images/opencv-task21ren-lian-jian-ce.png
---
# 人脸检测
```python
import cv2 as cv
import numpy as np


def face_detection(image):
    gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    face_detector = cv.CascadeClassifier("G:/haarcascade_frontalface_alt_tree.xml")
    faces = face_detector.detectMultiScale(gray, 1.2, 2)
    for x, y, w, h in faces:
        cv.rectangle(image, (x, y), (x+w, y+h), (0, 0, 255), 2)
    cv.imshow("result", image)
#    cv.waitKey(10)


def main():
#    src = cv.imread("G:/1.jpg")
#    cv.namedWindow("input image", cv.WINDOW_AUTOSIZE)
#
#    cv.imshow("input image", src)
#    face_detection(src)

    # 视频检测
    capture = cv.VideoCapture(0)
    cv.namedWindow("result", cv.WINDOW_AUTOSIZE)
    while True:
        ret, frame = capture.read()
        frame = cv.flip(frame, 1)
        face_detection(frame)
        c = cv.waitKey(10)
        if c == 27:
            break

    cv.waitKey(0)
    cv.destroyAllWindows()  # 关闭所有窗口


if __name__ == '__main__':
    main()
```
---
title: 'OpenCV Task2：numpy操作'
date: 2019-07-09 14:25:07
tags: [OpenCV]
published: true
hideInList: false
feature: /post-images/opencv-task2numpy-cao-zuo.png
---
# numpy基本操作

```python
import cv2 as cv
import numpy as np


def access_pixels(image):  # 获取图片高/宽/通道数
    print(image.shape)
    height = image.shape[0]
    width = image.shape[1]
    channels = image.shape[2]
    # 也可以直接写：
    # height, width, channels = image.shape[:]
    print("width: %s, height: %s, channels: %s"%(width, height, channels))

    new_image = image.copy()  # 复制一份image图片
    for row in range(height):
        for col in range(width):
            for c in range(channels):
                pv = image[row, col, c]
                new_image[row, col, c] = 256 - pv  # 图像反转

    cv.imshow('pixels_demo', new_image)


def create_image():
    """创建三维数组，0维为B，1维为G，2维为R"""
    img = np.zeros([400, 400, 3], np.uint8)
    img[:, :, 0] = np.ones([400, 400]) * 255
    cv.imshow("new_image", img)


def inverse(image):
    dst = cv.bitwise_not(image)  # 按位取反，白变黑，黑变白，效果和new_image一样
    cv.imshow("inverse_demo",dst)


print("----------Hello World!----------")
src = cv.imread("G:/2.jpg")  # 读入图片放进src中
cv.namedWindow("colin knight", cv.WINDOW_AUTOSIZE)  # 创建窗口, 窗口尺寸自动调整
cv.imshow("colin knight", src)  # 将src图片放入该创建的窗口中

t1 = cv.getTickCount()  # 获取当前电脑时钟滴答数
# create_image()
access_pixels(src)
inverse(src)
t2 = cv.getTickCount()
time = (t2 - t1)/cv.getTickFrequency()  # 函数执行前后滴答数之差与滴答频率之比为前后时间差
print("time: %s ms"%(time * 1000))
cv.waitKey(0)

```


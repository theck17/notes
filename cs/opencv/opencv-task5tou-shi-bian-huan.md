---
title: 'OpenCV Task5：透视变换与ROI'
date: 2019-07-09 14:57:11
tags: [OpenCV]
published: true
hideInList: false
feature: /post-images/opencv-task5tou-shi-bian-huan.png
---
# 透视变换
* 代码参考：https://blog.csdn.net/songchunxiao1991/article/details/80226510
```python
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# 学习对图像进行各种几个变换，例如移动，旋转，仿射变换等。
# 函数为：cv2.getPerspectiveTransform
# 变换 OpenCV提供了两个变换函数，cv2.warpAﬃne和cv2.warpPerspective，
# 使用这两个函数你可以实现所有类型的变换。
# cv2.warpAﬃne 接收的参数是 2×3 的变换矩阵，而 cv2.warpPerspective 接收的参数是 3×3 的变换矩阵。


# 扩展缩放只是改变图像的尺寸大小。OpenCV 提供的函数 cv2.resize() 可以实现这个功能。
# 图像的尺寸可以自己手动设置，你也可以指定缩放因子。
# 我们可以选择使用不同的插值方法。在缩放时我们推荐使用cv2.INTER_AREA，
# 在扩展时我们推荐使用 v2.INTER_CUBIC（慢) 和 v2.INTER_LINEAR。
#  默认情况下所有改变图像尺寸大小的操作使用的插值方法都是cv2.INTER_LINEAR。
def resize_demo(image):

    print("Origin size:", image.shape)
    # 第一种方法：通过fx，fy缩放因子
    res = cv.resize(image, None, fx=2, fy=2, interpolation=cv.INTER_CUBIC)
    print("After resize 1 size:", res.shape)
    # 第二种方法：直接设置输出图像的尺寸，所以不用设置缩放因子
    height,width = image.shape[:2]
    res=cv.resize(image,(2*width,2*height),interpolation=cv.INTER_CUBIC)
    print("After resize 2 size:", res.shape)

    while(1):
        cv.imshow('res',res)
        cv.imshow('img',image)
        if cv.waitKey(1) & 0xFF == 27:
            break


# 图像偏移：M = np.array([[1, 0, tx], [0, 1, ty]])
def move_demo(image):
    rows, cols = image.shape[:2]
    M = np.float32([[1, 0, 100], [0, 1, 50]])
    dst = cv.warpAffine(image, M, (cols, rows))
    cv.imshow('image', dst)


# 图像旋转
def rotation_demo(img):
    rows, cols = img.shape[:2]
    # 将图像相对于中心旋转90度，而不进行任何缩放。旋转中心，角度，缩放比率
    M = cv.getRotationMatrix2D((cols / 2, rows / 2), 90, 1)
    dst = cv.warpAffine(img, M, (cols, rows))
    cv.imshow('original', img)
    cv.imshow('result', dst)
    cv.waitKey(0)
    cv.destroyAllWindows()


# 仿射变换
# 在仿射变换中，原始图像中的所有平行线在输出图像中仍然是平行的。
# 为了找到变换矩阵，我们需要输入图像中的三个点以及它们在输出图像中的相应位置。
# 然后cv2.getAffineTransform将创建一个2x3矩阵，并将其传递给cv2.warpAffine。
def affine_demo(img):

    rows, cols, ch = img.shape

    pts1 = np.float32([[50, 50], [200, 50], [50, 200]])
    pts2 = np.float32([[10, 100], [200, 50], [100, 250]])

    M = cv.getAffineTransform(pts1, pts2)

    dst = cv.warpAffine(img, M, (cols, rows))

    plt.subplot(121), plt.imshow(img), plt.title('Input')
    plt.subplot(122), plt.imshow(dst), plt.title('Output')
    plt.show()


# 透视转化 对于透视变换，您需要一个3x3变换矩阵。 即使在改造之后，直线仍将保持直线。
# 要找到这个变换矩阵，您需要输入图像上的4个点和输出图像上的对应点。 在这4点中，其中3个不应该在线。
# 然后可以通过函数cv2.getPerspectiveTransform找到变换矩阵。
# 然后将cv2.warpPerspective应用于这个3x3转换矩阵。
def perspective_demo(img):

    rows, cols, ch = img.shape

    pts1 = np.float32([[56, 65], [368, 52], [28, 387], [389, 390]])
    pts2 = np.float32([[0, 0], [300, 0], [0, 300], [300, 300]])

    M = cv.getPerspectiveTransform(pts1, pts2)

    dst = cv.warpPerspective(img, M, (300, 300))

    plt.subplot(121), plt.imshow(img), plt.title('Input')
    plt.subplot(122), plt.imshow(dst), plt.title('Output')
    plt.show()


def main():
    src = cv.imread("G:/1.jpg")
    cv.namedWindow("image1", cv.WINDOW_AUTOSIZE) 
    cv.imshow("image1",src)
#    resize_demo(src)
#    move_demo(src)
#    rotation_demo(src)
#    affine_demo(src)
    perspective_demo(src)
    cv.waitKey(0)  # 等有键输入或者1000ms后自动将窗口消除，0表示只用键输入结束窗口
    cv.destroyAllWindows()  # 关闭所有窗口


if __name__ == '__main__':
    main()
```
# roi
```python
# roi 即兴趣区域，对图像提取想要的部分

import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt


def roi_test(src):
    face = src[100:510, 200:600]
    gray = cv.cvtColor(face, cv.COLOR_BGR2GRAY)  # face彩色图片变成灰度图片
    cv.imshow("gray", gray)
    back_face = cv.cvtColor(gray, cv.COLOR_GRAY2BGR)
    cv.imshow("back_face", back_face)
    src[100:510, 200:600] = back_face
    cv.imshow("face", src)


def fill_color_demo(image):
    copyImg = image.copy()# 拷贝一张图片
    h, w = image.shape[:2]
    mask = np.zeros([h+2, w+2], np.uint8)

    # 参数：原图，mask图，起始点，起始点值减去该值作为最低值，起始点值加上该值作为最高值，彩色图模式
    cv.floodFill(copyImg, mask, (30, 30), (0, 0, 255), (100,100,100), (50, 50, 50), cv.FLOODFILL_FIXED_RANGE)
    cv.imshow("fill_color_demo", copyImg)


def fill_binary():
    image = np.zeros([400, 400, 3], np.uint8)
    image[100:300, 100:300, :] = 255
    cv.imshow("fill_binary", image)

    mask = np.ones([402, 402, 1], np.uint8)
    mask[101:301, 101:301] = 0

    cv.floodFill(image, mask, (200, 200), (100, 2, 255), cv.FLOODFILL_MASK_ONLY)
    cv.imshow("filled binary", image)


def make_border(image):
    """
    :param image:输入图像
    top, bottom, left, right 对应边界的像素数目。
    borderType 要添加那种类型的边界，类型如下:
    – cv2.BORDER_CONSTANT 添加有颜色的常数值边界，还需要 下一个参数（value）。
    – cv2.BORDER_REFLECT边界元素的镜像。比如: fedcba|abcdefgh|hgfedcb
    – cv2.BORDER_REFLECT_101orcv2.BORDER_DEFAULT 跟上面一样，但稍作改动。例如: gfedcb|abcdefgh|gfedcba
    – cv2.BORDER_REPLICATE重复最后一个元素。例如: aaaaaa| abcdefgh|hhhhhhh
    – cv2.BORDER_WRAP 不知道怎么说了, 就像这样: cdefgh| abcdefgh|abcdefg
    value 边界颜色，如果边界的类型是 cv2.BORDER_CONSTANT
    """
    BLUE = [255, 0, 0]

    replicate = cv.copyMakeBorder(image, 10, 10, 10, 10, cv.BORDER_REPLICATE)
    reflect = cv.copyMakeBorder(image, 10, 10, 10, 10, cv.BORDER_REFLECT)
    reflect101 = cv.copyMakeBorder(image, 10, 10, 10, 10, cv.BORDER_REFLECT_101)
    wrap = cv.copyMakeBorder(image, 10, 10, 10, 10, cv.BORDER_WRAP)
    constant = cv.copyMakeBorder(image, 10, 10, 10, 10, cv.BORDER_CONSTANT, value=BLUE)

    plt.subplot(231), plt.imshow(image, 'gray'), plt.title('ORIGINAL')
    plt.subplot(232), plt.imshow(replicate, 'gray'), plt.title('REPLICATE')
    plt.subplot(233), plt.imshow(reflect, 'gray'), plt.title('REFLECT')
    plt.subplot(234), plt.imshow(reflect101, 'gray'), plt.title('REFLECT_101')
    plt.subplot(235), plt.imshow(wrap, 'gray'), plt.title('WRAP')
    plt.subplot(236), plt.imshow(constant, 'gray'), plt.title('CONSTANT')
    plt.show()


src = cv.imread("G:/2.jpg")  # 读入图片放进src中
cv.namedWindow("images")  # 创建窗口
cv.imshow("images", src)  # 将src图片放入该创建的窗口中
#roi_test(src)
#fill_color_demo(src)
#fill_binary()
img = cv.imread("G:/1.jpg")
make_border(img)
cv.waitKey(0) # 等有键输入或者1000ms后自动将窗口消除，0表示只用键输入结束窗口
cv.destroyAllWindows()  # 关闭所有窗口


```
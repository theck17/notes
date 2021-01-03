---
title: 'OpenCV Task9：背景检出'
date: 2019-07-09 20:19:05
tags: [OpenCV]
published: true
hideInList: false
feature: /post-images/opencv-task9.png
---
# 背景检出
```python
import cv2 as cv
import numpy as np


"""
在很多基础应用中背景检出都是一个非常重要的步骤。
例如顾客统计，使用一个静态摄像头来记录进入和离开房间的人数，或者是交通摄像头，需要提取交通工具的信息等。
在所有的这些例子中，首先要将人或车单独提取出来。技术上来说，我们需要从静止的背景中提取移动的前景。
如果图像中的交通工具还有影子的话，那这个工作就更难了，因为影子也在移动，
仅仅使用减法会把影子也当成前景,真是一件很复杂的事情。 
为了实现这个目的科学家们已经提出了几种算法。OpenCV 中已经包含了 其中三种比较容易使用的方法
"""


def create_background_sub():
    """
    BackgroundSubtractorMOG 这是一个以混合高斯模型为基础的前景/背景分割算法。
    它使用 K（K=3 或 5）个高斯分布混合对背景像素进行建模。使用这些颜色（在整个视频中）存在时间的长短作为混合的权重。
    背景的颜色一般持续的时间最长，而且更加静止。一个像素怎么会有分布呢？在 x，y 平面上一个像素就是一个像素没有分布，
    但是我们现在讲的背景建模是基于时间序列的，因此每一个像素点所在的位置在整个时间序列中就会有很多值，从而构成一个分布。
    在编写代码时，我们需要使用函数：cv2.createBackgroundSubtractorMOG() 创建一个背景对象。
    这个函数有些可选参数，比如要进行建模场景的时间长度， 高斯混合成分的数量，阈值等。将他们全部设置为默认值。
    然后在整个视频中我们是需要使用 backgroundsubtractor.apply() 就可以得到前景的掩模

    BackgroundSubtractorMOG2,也是以高斯混合模型为基础的背景/前景分割算法。
    这个算法的一个特点是它为每 一个像素选择一个合适数目的高斯分布。（上一个方法中我们使用是 K 高斯分布）。
    这样就会对由于亮度等发生变化引起的场景变化产生更好的适应。
     和前面一样我们需要创建一个背景对象。但在这里我们我们可以选择是否 检测阴影。
     如果 detectShadows = True（默认值），它就会检测并将影子标记 出来，但是这样做会降低处理速度。影子会被标记为灰色。

    """
    cap = cv.VideoCapture('G:/test.avi')

    # 创建一个背景对象
    # fgbg = cv.createBackgroundSubtractorKNN()
    fgbg = cv.createBackgroundSubtractorMOG2()

    while (1):
        ret, frame = cap.read()
        fgmask = fgbg.apply(frame)  # 将背景对象应用到当前帧中得到前景的掩模
        cv.imshow('frame', fgmask)
        k = cv.waitKey(30) & 0xff
        if k == 27:
            break

    cap.release()
    cv.destroyAllWindows()


def background_subtractorGMG():
    """
    此算法结合了静态背景图像估计和每个像素的贝叶斯分割。
    这是 2012 年 Andrew_B.Godbehere，Akihiro_Matsukawa 和 Ken_Goldberg 在文章 中提出的。
    它使用前面很少的图像（默认为前 120 帧）进行背景建模。使用了概率前景估计算法（使用贝叶斯估计鉴定前景）。
    这是一种自适应的估计，新观察到的 对象比旧的对象具有更高的权重，从而对光照变化产生适应。
    一些形态学操作 如开运算闭运算等被用来除去不需要的噪音。在前几帧图像中你会得到一个黑 色窗口。
     对结果进行形态学开运算对与去除噪声很有帮助。
    """
    cap = cv.VideoCapture('G:/test.avi')

    kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (3, 3))
    fgbg = cv.createBackgroundSubtractorKNN()

    while (1):
        ret, frame = cap.read()
        fgmask = fgbg.apply(frame)  # 将背景对象应用到当前帧中得到前景的掩模
        fgmask = cv.morphologyEx(fgmask, cv.MORPH_OPEN, kernel)

        cv.imshow('frame', fgmask)
        k = cv.waitKey(30) & 0xff
        if k == 27:
            break


def main():
#    create_background_sub()
    background_subtractorGMG()
    cv.waitKey(0)  # 等有键输入或者1000ms后自动将窗口消除，0表示只用键输入结束窗口
    cv.destroyAllWindows()  # 关闭所有窗口


if __name__ == '__main__':
    main()
```

```python
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt


def hist2d_demo(image):
    hsv = cv.cvtColor(image, cv.COLOR_BGR2HSV)
    hist = cv.calcHist([image], [0, 1], None, [180, 360], [0, 180, 0, 256])  # 计算直方图
    print(hist.shape)
    cv.imshow("hist2d_demo", hist)
    plt.imshow(hist, interpolation="nearest")  # 直方图显示
    plt.title("2D Histogram")
    plt.show()


# OpenCV 提供的函数 cv2.calcBackProject() 可以用来做直方图反向 投影。
# 它的参数与函数 cv2.calcHist 的参数基本相同。其中的一个参数是我 们要查找目标的直方图。
# 同样再使用目标的直方图做反向投影之前我们应该先对其做归一化处理。
# 返回的结果是一个概率图像
def back_projection_demo():
    """
    反向投影可以用来做图像分割，或者在图像中找寻我们感兴趣的部分。
    它会输出与输入图像（待搜索）同样大小的图像，其中的每一个像素值代表了输入图像上对应点属于目标对象的概率。
    输出图像中像素值越高（越白）的点就越可能代表我们要搜索的目标 （在输入图像所在的位置）。
    直方图投影经常与camshift 算法等一起使用。
    步骤：
    1. 为一张包含我们要查找目标的图像创建直方图，我们要查找的对象要尽量占满这张图像。
        最好使用颜色直方图，因为一个物体的颜色要比它的灰 度能更好的被用来进行图像分割与对象识别。
    2. 们再把这个颜色直方图投 影到输入图像中寻找我们的目标，
        也就是找到输入图像中的每一个像素点的像素值在直方图中对应的概率，这样我们就得到一个概率图像。
    3. 设置适当的阈值对概率图像进行二值化
    """
    sample = cv.imread("G:/1.jpg")
    target = cv.imread("G:/2.jpg")
    roi_hsv = cv.cvtColor(sample, cv.COLOR_BGR2HSV)
    target_hsv = cv.cvtColor(target, cv.COLOR_BGR2HSV)

    cv.imshow("sample", sample)
    cv.imshow("target", target)

    roiHist = cv.calcHist([roi_hsv], [0, 1], None, [180, 256], [0, 180, 0, 256])

    # 归一化：原始图像，结果图像，映射到结果图像中的最小值，最大值，归一化类型
    # cv.NORM_MINMAX对数组的所有值进行转化，使它们线性映射到最小值和最大值之间
    # 归一化后的图像便于显示，归一化后到0,255之间了
    cv.normalize(roiHist, roiHist, 0, 255, cv.NORM_MINMAX)
    dst = cv.calcBackProject([target_hsv], [0, 1], roiHist, [0, 180, 0, 256], 1)
    cv.imshow("backProjectionDemo", dst)


src = cv.imread("G:/2.jpg")  # 读入图片放进src中
cv.namedWindow("colin")  # 创建窗口
cv.imshow("colin", src)  # 将src图片放入该创建的窗口中
#hist2d_demo(src)
back_projection_demo()

cv.waitKey(0) # 等有键输入或者1000ms后自动将窗口消除，0表示只用键输入结束窗口
cv.destroyAllWindows()  # 关闭所有窗口
```

```python
# coding:utf8
import cv2 as cv
import numpy as np
import time


def mean_shift_demo():
    """
    原理：假设我们有一堆点（比如直方 图反向投影得到的点），和一个小的圆形窗口，
    我们要完成的任务就是将这个窗 口移动到最大灰度密度处（或者是点最多的地方）。

    例如，初始窗口“C1”，圆心“C1_o”，而窗口中所有点质心却是“C1_r”，此时圆心和点的质心没有重合。
    所以移动圆心 C1_o 到质心 C1_r，这样我们就得到了一个新的窗口。再找新窗口内所有点的质心，
    大多数情况下还是不重合的，所以重复上面的操作：将新窗口的中心移动到新的质心。
    就这样不停的迭代操作直到窗口的中心和其所 包含点的质心重合为止（或者有一点小误差）。
    按照这样的操作我们的窗口最终会落在像素值（和）最大的地方。

    通常情况下我们要使用直方图方向投影得到的图像和目标对象的起始位置。
    当目标对象的移动会反映到直方图反向投影图中。
    就这样，meanshift 算法就把我们的窗口移动到图像中灰度密度最大的区域了。

    要在 OpenCV 中使用 Meanshift 算法首先我们要对目标对象进行设置， 计算目标对象的直方图，
    这样在执行 meanshift 算法时我们就可以将目标对象反向投影到每一帧中去了。
    另外我们还需要提供窗口的起始位置。在这里我们只计算 H（Hue）通道的直方图，
    同样为了避免低亮度造成的影响，我们使用函数 cv2.inRange() 将低亮度的值忽略掉。
    """
    # cap = cv.VideoCapture('cv.gif')
    cap = cv.VideoCapture("G:/slow.mp4")
    ret, frame = cap.read()  # 获取第一帧

    # 设置初始窗口位置
    # r, h, c, w = 97, 130, 450, 125
    r, h, c, w = 210, 80, 300, 125  # r,c 左上角坐标，h,w 高宽
    track_window = (c, r, w, h)

    # 设置兴趣区域
    roi = frame[r:r+h, c:c+w]

    hsv_roi = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    # 设置掩模，即剔除部分影响亮度的值
    mask = cv.inRange(hsv_roi, np.array((0., 60., 32.)), np.array((180., 255., 255.)))

    # 计算直方图
    roi_hist = cv.calcHist([hsv_roi], [0], mask, [180], [0, 180])
    cv.normalize(roi_hist, roi_hist,0, 255, cv.NORM_MINMAX)  # 归一化

    # 设置迭代条件，10次迭代，或至少移动一次
    term_crit = (cv.TERM_CRITERIA_EPS | cv.TERM_CRITERIA_COUNT, 10, 1)

    while True:
        ret, frame = cap.read()

        if ret is True:
            hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
            dst = cv.calcBackProject([hsv], [0], roi_hist, [0, 180], 1)

            # 用meanShift算法获得新窗口，从而实现迭代
            ret, track_window = cv.meanShift(dst, track_window, term_crit)

            # 在图片中画出该识别出来的窗口
            x, y, w, h = track_window
            img2 = cv.rectangle(frame, (x, y), (x + w, y + h), 255, 2)
            cv.imshow('img2', img2)

            c = cv.waitKey(60) & 0xff
            if c == 27:
                break
            else:
                print(c)
                print(time.strftime('%H_%M_%S',time.localtime(time.time())))
                cv.imwrite(time.strftime('%H_%M_%S',time.localtime(time.time()))+'.jpg', img2)
        else:
            break


def cam_shift_demo():
    """
    我们的窗口的大小是固定的，而汽车由远及近（在视觉上）是一个逐渐变大的过程，固定的窗口是不合适的。
    所以我们需要根据目标的大小和角度来对窗口的大小和角度进行修订。
    OpenCVLabs 为我们带来的解决方案（1988 年）：一个被叫做 CAMshift的算法。
    这个算法首先要使用 meanshift，meanshift 找到（并覆盖）目标之后， 再去调整窗口的大小。
    它还会计算目标对象的最佳外接椭圆的 角度，并以此调节窗口角度。
    然后使用更新后的窗口大小和角度来在原来的位 置继续进行 meanshift。
    重复这个过程知道达到需要的精度。
    OpenCV中Camshift与 Meanshift 基本一样，但是返回的结果是一个带旋转角度的矩形（这是 我们的结果），
    以及这个矩形的参数（被用到下一次迭代过程中）。
    """
    cap = cv.VideoCapture("G:/slow.mp4")
    ret, frame = cap.read()  # 获取第一帧

    # 设置初始窗口位置
    r, h, c, w = 210, 80, 300, 125  # r,c 左上角坐标，h,w 高宽
    track_window = (c, r, w, h)

    # 设置兴趣区域
    roi = frame[r:r + h, c:c + w]

    hsv_roi = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    # 设置掩模，即剔除部分影响亮度的值
    mask = cv.inRange(hsv_roi, np.array((0., 60., 32.)), np.array((180., 255., 255.)))

    # 计算直方图
    roi_hist = cv.calcHist([hsv_roi], [0], mask, [180], [0, 180])
    cv.normalize(roi_hist, roi_hist, 0, 255, cv.NORM_MINMAX)  # 归一化

    # 设置迭代条件，10次迭代，或至少移动一次
    term_crit = (cv.TERM_CRITERIA_EPS | cv.TERM_CRITERIA_COUNT, 10, 1)

    while True:
        ret, frame = cap.read()

        if ret is True:
            hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
            dst = cv.calcBackProject([hsv], [0], roi_hist, [0, 180], 1)

            # 用meanShift算法获得新窗口，从而实现迭代
            ret, track_window = cv.CamShift(dst, track_window, term_crit)
            print(ret)

            # ret 为元组类型，分别为矩形左上角和右下角，以及旋转角度，
            # 用boxPoints()和polylines()恰好可以画出这个旋转矩形
            pts = cv.boxPoints(ret)
            pts = np.int0(pts)
            img2 = cv.polylines(frame, [pts], True, 255, 2)
            cv.imshow('img2', img2)

            c = cv.waitKey(60) & 0xff
            if c == 27:
                break
            else:
                print(c)
                print(time.strftime('%H_%M_%S', time.localtime(time.time())))
                cv.imwrite(time.strftime('%H_%M_%S', time.localtime(time.time())) + '.jpg', img2)
        else:
            break


def main():
    # mean_shift_demo()
    cam_shift_demo()
    cv.waitKey(0)  # 等有键输入或者1000ms后自动将窗口消除，0表示只用键输入结束窗口
    cv.destroyAllWindows()  # 关闭所有窗口


if __name__ == '__main__':
    main()
```

```python
import cv2 as cv
import numpy as np

# 由于目标对象或者摄像机的移动造成的图像对象在连续两帧图像中的移动 被称为光流。
# 它是一个2D向量场，可以用来显示一个点从第一帧图像到第二 帧图像之间的移动。
# 光流在很多领域中都很有用
# • 由运动重建结构
# • 视频压缩
# • Video Stabilization 等
#
# 从使用者的角度来看，想法很简单，我们取跟踪一些点，然后我们就会获得这些点的光流向量。
# 但是还有一些问题。直到现在我们处理的都是很小的运动。
#  如果有大的运动怎么办呢？图像金字塔。我们可以使用图像金字塔的顶层，
# 此时小的运动被移除，大的运动装换成了小的运动，现在再使用 Lucas-Kanade 算法，我们就会得到尺度空间上的光流。


def optical_flow_demo():
    """
    函数目的：跟踪视频中的一些点。使用函数 cv2.goodFeatureToTrack()来确定要跟踪的点。
    首先在视频的第一帧图像中检测一些Shi-Tomasi角点，然后我们使用Lucas Kanade算法迭代跟踪这些角点。

    要给函数cv2.calcOpticlaFlowPyrLK()传入前一帧图像和其中的点，以及下一帧图像。
    函数将返回带有状态数的点， 如果状态数是 1，那说明在下一帧图像中找到了这个点（上一帧中角点），
    如果状态数是 0，就说明没有在下一帧图像中找到这个点。
    我们再把这些点作为参数传给函数，如此迭代下去实现跟踪。

    图像中的一些特征点甚至 在丢失以后，光流还会找到一个预期相似的点。
    所以为了实现稳定的跟踪，应该每个一定间隔就要进行一次角点检测。

    OpenCV 的官方示例中带有这样一个例子，它是每 5 帧进行一个特征点检测。
    它还对光流点使用反向检测来选取好的点进行跟踪
    """
    cap = cv.VideoCapture('G:/slow.mp4')

    # 用字典的方式传给goodFeaturesToTrack() 用来角点检测
    feature_params = dict( maxCorners = 100, qualityLevel = 0.3, minDistance = 7, blockSize = 7 )

    # maxLevel 为使用的图像金字塔层数
    lk_params = dict(winSize=(15, 15), maxLevel=2, criteria=(cv.TERM_CRITERIA_EPS | cv.TERM_CRITERIA_COUNT, 10, 0.03))
    # Create some random colors
    color = np.random.randint(0,255,(100,3))

    ret, old_frame = cap.read()
    old_gray = cv.cvtColor(old_frame, cv.COLOR_BGR2GRAY)
    p0 = cv.goodFeaturesToTrack(old_gray, mask=None, **feature_params)

    mask = np.zeros_like(old_frame)

    while True:
        ret, frame = cap.read()
        frame_gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

        # cv.calcOpticalFlowPyrLK()参数说明：前一帧图像，吼一帧图像，前一帧的特征点
        # 返回参数说明，后一帧对应的特征点，状态值（如果前一帧特征点在后一帧存在st=1，不存在st=0），err:前后帧特征点误差
        p1, st, err = cv.calcOpticalFlowPyrLK(old_gray, frame_gray, p0, None, **lk_params)

        # 提取前后帧都存在的特征点
        good_new = p1[st == 1]
        good_old = p0[st == 1]

        for i, (new, old) in enumerate(zip(good_new, good_old)):  # zip打包函数
            a, b = new.ravel()  # 将特征点分解开，得到对应的坐标点
            c, d = old.ravel()
            mask = cv.line(mask, (a, b), (c, d), color[i].tolist(), 2)  # 随机获得线条，圆的颜色
            frame = cv.circle(frame, (a, b), 5, color[i].tolist(), -1)
        img = cv.add(frame, mask)

        cv.imshow("frame",img)
        k = cv.waitKey(30) & 0xff
        if k == 27:
            break

        old_gray = frame_gray.copy()
        p0 = good_new.reshape(-1, 1, 2)

    cv.destroyAllWindows()
    cap.release()


def Farneback():
    """
    ucas-Kanade 法是计算一些特征点的光流。OpenCV 还提供了一种计算稠密光流的方法。
    它会图像中的所有点的光流。这是基于 Gunner_Farneback 的算法 （2003 年）。
    结果是一个带有光流向量 （u，v）的双通道数组。通过计算我们能得到光流的大小和方向。
    使用颜色对结果进行编码以便于更好的观察。
    方向对应于 H（Hue）通道，大小对应 于 V（Value）通道
    :return:
    """
    cap = cv.VideoCapture("G:/vtest.avi")
    ret, frame1 = cap.read()
    prvs = cv.cvtColor(frame1, cv.COLOR_BGR2GRAY)
    hsv = np.zeros_like(frame1)
    hsv[..., 1] = 255  # 将第二列都置为255


    while True:
        ret, frame2 = cap.read()
        next = cv.cvtColor(frame2,cv.COLOR_BGR2GRAY)
        flow = cv.calcOpticalFlowFarneback(prvs, next, None, 0.5, 3, 15, 3, 5, 1.2, 0)

        mag, ang = cv.cartToPolar(flow[..., 0], flow[..., 1])
        hsv[..., 0] = ang * 180 / np.pi / 2
        hsv[..., 2] = cv.normalize(mag, None, 0, 255, cv.NORM_MINMAX)
        rgb = cv.cvtColor(hsv, cv.COLOR_HSV2BGR)
        cv.imshow('frame2', rgb)
        k = cv.waitKey(30) & 0xff
        if k == 27:
            break
        elif k == ord('s'):
            cv.imwrite('G:/test1.png', frame2)
        cv.imwrite('G:/test2.png', rgb)
        prvs = next

    cap.release()
    cv.destroyAllWindows()


def main():
    # optical_flow_demo()
    Farneback()
    cv.waitKey(0)  # 等有键输入或者1000ms后自动将窗口消除，0表示只用键输入结束窗口
    cv.destroyAllWindows()  # 关闭所有窗口


if __name__ == '__main__':
    main()
```
---
title: 'OpenCV Task1：图片和视频的读取'
date: 2019-07-09 09:10:11
tags: [OpenCV]
published: true
hideInList: false
feature: /post-images/opencv.png
---
# OpenCV

# 安装

* pip install opencv-python

* pip install openc-contrib_python

* pip install pytesseract

# 读取图像

```python
import cv2 as cv
import numpy as np  

# 打印图像信息
def get_image_info(image):
    print("图像类型：",type(image))
    print("图像长x宽x通道数：",image.shape)
    print("图像长宽通道数相乘所得值：",image.size)
    print("图像像素值类型：",image.dtype)
    pixel_data = np.array(image)  # 将图片转换成数组
    print("像素大小：", pixel_data)

print("==================================================")
src = cv.imread("G:/2.jpg")# 读入图片放进src中
get_image_info(src) # 打印图像信息
# 创建窗口, 窗口可以调整大小， 但是标签改成cv2.WINDOW_NORMAL，也可调整窗口大小。
# 当图像维度太大, 或者要添加轨迹条时，调整窗口大小将会很有用
cv.namedWindow("input image", cv.WINDOW_AUTOSIZE)# 创建窗口, 窗口尺寸自动调整
cv.imshow("input image", src)# 将src图片放入该创建的窗口中
cv.waitKey(1000)# 等有键输入或者1000ms后自动将窗口消除，0表示只用键输入结束窗口

cv.destroyAllWindows()
# 与从摄像头中捕获一样，你只需要把设备索引号改成视频文件的名字。
# 在播放每一帧时，使用 cv.waiKey() 设置适当的持续时间。
# 如果设置的太低视频就会播放的非常快，如果设置的太高就会播放的很慢（你可以使用这种方法控制视频的播放速度）。
# 通常情况下 25 毫秒就可以了。
# cv2.waitKey() 是一个键盘绑定函数。需要指出的是它的时间尺度是毫秒级。
# 函数等待特定的几毫秒，看是否有键盘输入。
# 特定的几毫秒之内，如果按下任意键，这个函数会返回按键的 ASCII 码值，程序将会继续运行。
# 如果没有键盘输入，返回值为-1，如果我们设置这个函数的参数为0，那它将会无限 期的等待键盘输入。
# 它也可以被用来检测特定键是否被按下，

# cv2.destroyAllWindows() 可以轻易删除任何我们建立的窗口。
# 如果 你想删除特定的窗口可以使用 cv2.destroyWindow()，在括号内输入你想删除的窗口名。
```

# 保存图片

```python
import cv2 as cv


def save_image(image):
    gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)  # 将src图片转换成灰度图
    cv.imwrite("output.png", gray)  # 将转化后的灰度图写入到GrayCrystal.png中，可以用来转换图片格式
```



# 读取视频

``` python
import cv2 as cv


# 获取视频
def video_demo():
    # 参数可以是设备的索引号，或者是一个视频文件(没有声音)。
    # 设备索引号就是在指定要使用的摄像头。 一般的笔记本电脑都有内置摄像头。所以参数就是 0。
    # 你可以通过设置成 1 或 者其他的来选择别的摄像头
    capture = cv.VideoCapture(0)# 调用摄像头
    # 你可以使用函数 capture.get(propId) 来获得视频的一些参数信息。
    # 这里 propId 可以是 0 到 18 之间的任何整数。
    # 其中的一些值可以使用 capture.set(propId,value) 来修改，value 就是 你想要设置成的新值。
    # 例如，我可以使用 capture.get(3) 和 cap.get(4) 来查看每一帧的宽和高。默认情况下得到的值是 640X480。
    # 但是我可以使用 ret=capture.set(3,320) 和 ret=capture.set(4,240) 来把宽和高改成 320X240
    print("类型",type(capture))
    while True:
        ret, frame = capture.read()  # 获取相机图像，返回ret(结果为True/False)，和每一帧图片
        frame = cv.flip(frame, 1)  # 将图片水平翻转，竖直翻转为0，左右为-1
        print('1', ret)  # 打印出ret值
        cv.imshow("video", frame)  # 将每一帧图片放入video窗口

        # 但是如果你用的是64位系统，你需要将k = cv.waitKey(0)这行改成 k = cv.waitKey(0)&0xFF。
        c = cv.waitKey(50) # 等有键输入(这里指c=Esc键)或者50ms后自动将窗口消除
        if c == 27:
            break
```

# 保存视频

```python
import cv2 as cv


# 视频保存，通过创建一个VideoWriter对象。
def save_video():
    cap = cv.VideoCapture(0)# 调用摄像头
    # 指定 FourCC 编码格式。
    # 播放频率和帧的大小也都需要确定。
    # 最后一个是 isColor 标签。如果是 True，每一帧就是彩色图，否则就是灰度图
    # FourCC 就是一个 4 字节码，用来确定视频的编码格式。
    # 可用的编码列表 可以从fourcc.org查到。这是平台依赖的。
    # 在Windows上常用的是DIVX。FourCC码以cv.VideoWriter_fourcc('D', 'I','V', 'X')形式传给程序
    fourcc = cv.VideoWriter_fourcc('D', 'I','V', 'X')

    # 参数说明：输出视频名称，编码格式，播放频率，帧的大小
    out = cv.VideoWriter("output.avi", fourcc, 50.0, (640, 480))

    while cap.isOpened(): # 你可以使用 cap.isOpened()，来检查是否成功初始化了
        ret, frame = cap.read()# 获取相机图像，返回ret(结果为True/False)，和每一帧图片
        if ret is True:
            out.write(frame)

            cv.imshow('frame', frame)
			# 当按下q键时，显示图片的窗口被关掉
            # 关于为什么要有0xFF,在某些系统上，waitKey（）可能会返回一个编码不仅仅是ASCII键码的值。在所有系统上，我们可以通过从返回值中读取最后一个字节来确保只提取ASCII键码
            if cv.waitKey(1) & 0xFF == ord('q'):
                break
        else:
            break

    cap.release()
    out.release()
```

# 查看所有被支持的鼠标事件

```python
import cv2 as cv

# 查看所有被支持的鼠标事件
def search_event():
    events = [i for i in dir(cv) if 'EVENT' in i]
    print(events)

print("----------colin be night----------")
img = cv.imread("G:/2.jpg")  # 读入图片放进src中
cv.namedWindow("image", cv.WINDOW_AUTOSIZE)  # 创建窗口, 窗口尺寸自动调整
search_event()#查看所有被支持的鼠标事件

while True:
    cv.imshow('image', img)# 显示图片
    if cv.waitKey(20) & 0xFF == 27:# 按ESC退出循环
        break

cv.destroyAllWindows()# 关闭窗口
```

# 创建图像与窗口并将窗口与回调函数绑定

```python
#setMouseCallback()函数是用来处理鼠标动作的函数，我们可以利用它来做有用的操作 
#OpenCV处理鼠标动作，首先需要创建一个回调函数，当鼠标事件触发时，该函数执行
#event
EVENT_MOUSEMOVE 0            #滑动
EVENT_LBUTTONDOWN 1          #左键点击
EVENT_RBUTTONDOWN 2          #右键点击
EVENT_MBUTTONDOWN 3          #中键点击
EVENT_LBUTTONUP 4            #左键放开
EVENT_RBUTTONUP 5            #右键放开
EVENT_MBUTTONUP 6            #中键放开
EVENT_LBUTTONDBLCLK 7        #左键双击
EVENT_RBUTTONDBLCLK 8        #右键双击
EVENT_MBUTTONDBLCLK 9        #中键双击
#flags
EVENT_FLAG_LBUTTON 1       #左鍵拖曳  
EVENT_FLAG_RBUTTON 2       #右鍵拖曳  
EVENT_FLAG_MBUTTON 4       #中鍵拖曳  
EVENT_FLAG_CTRLKEY 8       #(8~15)按Ctrl不放事件  
EVENT_FLAG_SHIFTKEY 16     #(16~31)按Shift不放事件  
EVENT_FLAG_ALTKEY 32       #(32~39)按Alt不放事件 
```



```python
import cv2 as cv


img = cv.imread("G:/2.jpg")  # 读入图片放进src中
cv.namedWindow("image", cv.WINDOW_AUTOSIZE)  # 创建窗口, 窗口尺寸自动调整
#search_event()
# 创建图像与窗口并将窗口与回调函数绑定
# event代表鼠标点击事件
# x,y，代表鼠标位于窗口的（x，y）坐标位置，默认左上角为原点，向右为x正轴，向下为y正轴
# flags代表鼠标滑动事件
# param代表回调函数的参数
def draw_circle(event, x, y, flags, param):
    if event == cv.EVENT_LBUTTONDBLCLK:
        cv.circle(img,(x,y),50,(255,255 ,255),5)
#    可以用代号替换事件
#	if event == 7:
#        cv.circle(img,(x,y),50,(255,255 ,255),5)
cv.setMouseCallback('image', draw_circle)

while True:
    cv.imshow('image', img)
    if cv.waitKey(20) & 0xFF == 27:
        break

cv.destroyAllWindows()
```

# 创建一个画板，可以自选各种颜色的画笔绘画各种图形

```python
import cv2 as cv
import numpy as np


# 当鼠标按下时变为 True
drawing=False
# 如果mode为true绘制矩形。按下 'm'变成绘制曲线。
mode = True
ix, iy = -1, -1


# 创建回调函数
def draw_circle(event, x, y, flags, param):
    # 参数：滑动条的名字，滑动条被放置窗口的名字
    r = cv.getTrackbarPos('R', 'image')
    g = cv.getTrackbarPos('G', 'image')
    b = cv.getTrackbarPos('B', 'image')
    color = (b, g, r)

    global ix, iy, drawing, mode

    # 当按下左键是返回起始位置坐标
    if event == cv.EVENT_LBUTTONDOWN:
        drawing = True
        ix, iy = x, y
    # 当鼠标左键按下并移动是绘制图型。event 可以查看移动，flag 查看查看是否按下
    elif event == cv.EVENT_MOUSEMOVE and flags == cv.EVENT_FLAG_LBUTTON:
        if drawing is True:
            if mode is True:
                cv.rectangle(img, (ix, iy), (x, y), color, -1)
            else:
                cv.circle(img, (x, y), 3, color, 1)
                # 下面注释掉的代码是起始点为圆心，起点到终点为半径的
                #  r=int(np.sqrt((x-ix)**2+(y-iy)**2))
                #  cv2.circle(img,(x,y),r,(0,0,255),-1)

    elif event == cv.EVENT_LBUTTONUP:
        drawing = False

        # if mode is True:
        #     cv.rectangle(img, (ix, iy), (x, y),(0, 255,0), -1)
        #
        # else:
        #     cv.circle(img, (x, y), 5, (0, 0, 255), -1)


# 回调函数，什么也不做
def nothing(x):
    pass


img = cv.imread("G:/2.jpg")
cv.namedWindow("image")
# 参数：滑动条的名字，滑动条被放置窗口的名字，滑动条的默认位置，滑动条的最大值，回调函数。
# 每次滑动条的滑动都会调用回调函数。回调函数通常都会含有一个默认参数，就是滑动条的位置。
# 在本例中这个函数不用做任何事情，我们只需要 pass 就可以了。
cv.createTrackbar('R','image',0,255,nothing)
cv.createTrackbar('G','image',0,255,nothing)
cv.createTrackbar('B','image',0,255,nothing)
cv.setMouseCallback('image', draw_circle)
while(1):
    cv.imshow('image',img)
    k = cv.waitKey(1)&0xFF
    if k == ord('m'):
        mode = not mode
#        if k == 27:
#            mode = not mode
#            break
    elif k == 27:
        break

cv.destroyAllWindows()
```

# 绘图函数：

* cv2.line()：绘制直线
* cv2.circle()：绘制圆
* cv2.rectangle()：绘制矩形
* cv2.ellipse()：绘制椭圆
* cv2.putText()：添加文字

```python
def draw_demo(img):
    # line(img, pt1, pt2, color[, thickness[, lineType[, shift]]]) -> img
    # pt1,pt2起点终点。
    # thickness线宽。如果给一个闭合图形设置为 -1，那么这个图形就会被填充。默认值是 1.
    # ：线条的类型， 8连接，抗锯齿等。默认情况是8连接。cv2.LINE_AA 为抗锯齿，这样看起来会非常平滑
    cv.line(img, (0, 0), (511, 511), (0, 0, 255), 5)
    cv.rectangle(img,(384,0),(510,128),(0,255,0),3)
    cv.circle(img,(447,63), 63, (0,0,255), -1)  # 中心点，半径，颜色，填充

    # 椭圆一个参数是中心点的位置坐标。 下一个参数是长轴和短轴的长度。椭圆沿逆时针方向旋转的角度。
    # 椭圆弧沿着顺时针方向起始的角度和结束角度（只画出一部分椭圆），如果是 0 很 360，就是整个椭圆。
    cv.ellipse(img,(256,256),(100,50),0,0,180,255,-1)

    # 这里 reshape 的第一个参数为 -1, 表明这一维的长度是根据后面的维度的计算出来的。
    # 注意：如果第三个参数是 False，我们得到的多边形是不闭合的（首尾不相 连）。
    # 注意：cv2.polylines() 可以被用来画很多条线。
    # 只需要把想要画的线放在一 个列表中，将这个列表传给函数就可以了。每条线都会被独立绘制。
    # 这会比用 cv2.line() 一条一条的绘制要快一些
    pts = np.array([[10, 5], [20, 30], [70, 20], [50, 10]], np.int32)
    pts = pts.reshape((-1, 1, 2))
    cv.polylines(img,pts=pts,isClosed=True, color=(255, 255, 255), thickness=3)

    """
    要在图片上绘制文字，你需要设置下列参数： 
    • 你要绘制的文字 
    • 你要绘制的位置 
    • 字体类型（通过查看 cv2.putText() 的文档找到支持的字体） 
    • 字体的大小 
    • 文字的一般属性如颜色，粗细，线条的类型等。
    为了更好看一点推荐使用 linetype=cv2.LINE_AA。 
    
    警告：所有的绘图函数的返回值都是 None，
    所以不能使用 img = cv2.line(img,(0,0),(511,511),(255,0,0),5)。
    """
    font = cv.FONT_HERSHEY_SIMPLEX
    cv.putText(img, 'OpenCV', (10, 500), font, 4, (255, 255, 255), 2)
    cv.imshow("example", img)


def main():
    cv.namedWindow("example")
    img = np.zeros((512, 512, 3), np.uint8)  # 创建一张图片
    draw_demo(img)

    cv.waitKey(0)  # 等有键输入或者1000ms后自动将窗口消除，0表示只用键输入结束窗口
    cv.destroyAllWindows()  # 关闭所有窗口


if __name__ == '__main__':
    main()
```


 [TOC]




# 技术基础

## 魔数0x5f3759df

下列代码是在《雷神之锤 III 竞技场》源代码中的一个函数（已经剥离了 C 语言预处理器的指令）。其实，最早在 2002 年（或 2003 年）时，这段平方根倒数速算法的代码就已经出现在 Usenet 与其他论坛上了，并且也在程序员圈子里引起了热烈的讨论。我先把这段代码贴出来，具体如下：

```c

float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y; // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );  // what the fuck? 
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );  // 1st iteration 
    // 2nd iteration, this can be removed
    // y  = y * ( threehalfs - ( x2 * y * y ) ); 

    return y;
}
```

这段代码初读起来，我是完全不知所云，尤其是那个魔数 0x5f3759df，根本不知道它是什么意思，所以，注释里也是 What the fuck。今天的这篇文章里，我主要就是想带你来了解一下这个函数中的代码究竟是怎样出来的。其实，这个函数的作用是求平方根倒数，即 
$$
x^{-1 / 2}
$$
也就是下面这个算式：
$$
\frac{1}{\sqrt{x}}
$$
当然，它算的是近似值。只不过这个近似值的精度很高，而且计算成本比传统的浮点数运算平方根的算法低太多。在以前那个计算资源还不充分的年代，在一些 3D 游戏场景的计算机图形学中，要求取照明和投影的光照与反射效果，就经常需要计算平方根倒数，而且是大量的计算——对一个曲面上很多的点做平方根倒数的计算。也就是需要用到下面的这个算式，其中的 x,y,z 是 3D 坐标上的一个点的三个坐标值。
$$
\frac{1}{\sqrt{x^{2}+y^{2}+z^{2}}}
$$
基本上来说，在一个 3D 游戏中，我们每秒钟都需要做上百万次平方根倒数运算。而在计算硬件还不成熟的时代，这些计算都需要软件来完成，计算速度非常慢。我们要知道，在上世纪 90 年代，多数浮点数操作的速度更是远远滞后于整数操作。所以，这段代码所带来的作用是非常大的。

### 计算机的浮点数表示

为了讲清楚这段代码，我们需要先了解一下计算机的浮点数表示法。在 C 语言中，计算机的浮点数表示用的是 IEEE 754 标准，这个标准的表现形式其实就是把一个 32bits 分成三段。

* 第一段占 1bit，表示符号位。代称为 S（sign）。
* 第二段占 8bits，表示指数。代称为 E（Exponent）。
* 第三段占 23bits，表示尾数。代称为 M（Mantissa）。

然后呢，一个小数的计算方式是下面这个算式：
$$
(-1)^{S} *\left(1+\frac{M}{2^{23}}\right) * 2^{(E-127)}
$$


下面，让我来试着解释一下浮点数的那三段表示什么意思

* 第一段符号位
* 第二段指数位。什么叫指数？也就是说，对于任何数 x，其都可以找到一个 n，使得 $$2^{n}$$ <=x<=$$2^{n+1}$$。比如：对于 3 来说，因为 2 < 3 < 4，所以 n=1。而浮点数的这个指数为了要表示 0.00x 的小数，所以需要有负数，这 8 个 bits 本来可以表示 0-255。为了表示负的，取值要放在 [-127,128] 这个区间中。这就是为什么我们在上面的公式中看到的 $$2^{(E-127)}$$ 这一项了。也就是说，n=E−127，如果 n=1，那么 E 就是 128 了。
* 第三段尾数位。也就是小数位，但是这里叫偏移量可能好一些。这里的取值是从[ 0 - $$2^{23}$$]中。你可以认为，我们把一条线分成 $$2^{23}$$ 个线段，也就是 8388608 个线段。也就是说，把 $$2^{n}$$到 $$2^{n+1}$$ 分成了 8388608 个线段。而存储的 M 值，就是从 2n 到 x 要经过多少个段。这要计算一下，$$2^{n}$$ 到 x 的长度占 $$2^{n}$$ 到$$2^{n+1}$$长度的比例是多少。

比如说，对 3.14 这个小数。

* 是正数。所以，S = 0
* $$2^{1}$$ < 3.14 <$$2^{2}$$。所以，n=1， n+127 = 128。所以，E=128。
* (3.14 - 2) / (4 - 2) = 0.57， 而 0.57∗$$2^{23}$$=4781506.56，四舍五入，得到 M = 4781507。因为有四舍五入，所以，产生了浮点数据的精度问题。把 S、E、M 转成二进制，得到 3.14 的二进制表示

我们再用 IEEE 754 的那个算式来算一下：
$$
(-1)^{0} *\left(1+\frac{4781507}{2^{23}}\right) * 2^{(128-127)}
$$

$$
1 *(1+0.5700000524520874) * 2
$$

$$
=3.1400001049041748046875
$$

你看，浮点数的精度问题出现了。

我们再来看一个示例，小数 0.015。

* 是正数。所以，S = 0。
* $$2^{-7}$$<0.015<$$2^{-6}$$ 。所以，n=-7， n+127 = 120。所以，E=120。
* (0.015−$$2^{-7}$$)/($$2^{-6}$$−$$2^{-7}$$) = 0.0071875/0.0078125=0.92。而 0.92∗$$2^{23}$$=7717519.36，四舍五入，得到 M = 7717519。

其中：

120 的二进制是 01111000

7717519 的二进制是 11101011100001010001111

返回过来算一下：
$$
(-1)^{0} *\left(1+\frac{7717519}{2^{23}}\right) * 2^{(120-127)}
$$

$$
(1+0.919999957084656) * 0.0078125
$$

$$
=0.014999999664724
$$

浮点数的精度问题又出现了

我们来用 C 语言验证一下：

```c

int main() {
    float x = 3.14;
    float y = 0.015;
    return 0;
}
```

在我的 Mac 上用 lldb 工具 Debug 一下。

```c

(lldb) frame variable
(float) x = 3.1400001
(float) y = 0.0149999997

(lldb) frame variable -f b
(float) x = 0b01000000010010001111010111000011
(float) y = 0b00111100011101011100001010001111
```

### 简化浮点数公式

因为那个浮点数表示的公式有点复杂，我们简化一下：
$$
(-1)^{S} *\left(1+\frac{M}{2^{23}}\right) * 2^{(E-127)}
$$
我们令，$$
m=\left(\frac{M}{2^{23}}\right)
$$，e=(E−127)。因为符号位在 y$$
=x^{-\frac{1}{2}}
$$ 的两端都是 0（正数），也就可以去掉，所以浮点数的算式简化为：
$$
(1+m) * 2^{e}
$$
上面这个算式是从一个 32bits 二进制计算出一个浮点数。这个 32bits 的整型算式是：
$$
M+E * 2^{23}
$$
比如，0.015 的 32bits 的二进制是：00111100011101011100001010001111，也就是整型的：

7717519+120∗$$2^{23}$$=1014350479=0X3C75C28F

### 平方根倒数公式推导

$$
y=\frac{1}{\sqrt[2]{x}}=x^{-\frac{1}{2}}
$$



等式两边取以 2 为基数的对数，就有了：
$$
\log _{2}(y)=-\frac{1}{2} \log _{2}(x)
$$
因为我们实际上在算浮点数，所以将公式中的 x 和 y 分别用浮点数的那个浮点数的简化算式 (1+m)∗$$2^{e}$$ 替换掉。代入 log() 公式中，我们也就有了下面的公式：
$$
\log _{2}\left(1+m_{y}\right)+e_{y}
$$

$$
=-\frac{1}{2}\left(\log _{2}\left(1+m_{x}\right)+e_{x}\right)
$$

因为有对数，这公式看着就很麻烦，似乎不能再简化了。但是，我们知道，所谓的 mx 或是 my，其实是个在 0 和 1 区间内的小数。在这种情况下，$$
\log _{2}(1 . x)
$$ 接近一条直线。

那么我们就可以使用一个直线方程来代替，也就是：
$$
\log _{2}(1+m) \approx m+\sigma
$$
于是，我们的公式就简化成了：
$$
m_{y}+\sigma+e_{y} \approx-\frac{1}{2}\left(m_{x}+\sigma+e_{x}\right)
$$
因为 $$
m=\left(\frac{M}{2^{23}}\right)
$$，e=(E−127)，代入公式，得到：
$$
\frac{M_{y}}{2^{23}}+\sigma+E_{y}-127
$$

$$
\approx-\frac{1}{2}\left(\frac{M_{x}}{2^{23}}+\sigma+E_{x}-127\right)
$$

移项整理一下，把 σ 和 127 从左边，移到右边：
$$
\frac{M_{y}}{2^{23}}+E_{y} \approx-\frac{1}{2}\left(\frac{M_{x}}{2^{23}}+E_{x}\right)-\frac{3}{2}(\sigma-127)
$$
再把整个表达式乘以 $$2^{23}$$，得到：$$
M_{y}+E_{y} 2^{23}
$$$$
\approx-\frac{1}{2}\left(M_{x}+E_{x} 2^{23}\right)-\frac{3}{2}(\sigma-127) 2^{23}
$$

可以看到一个常数：$$
-\frac{3}{2}(\sigma-127) 2^{23}
$$，把负号放进括号里，变成$$
\frac{3}{2}(127-\sigma) 2^{23}
$$，并可以用一个常量代数 R 来取代，于是得到公式：
$$
M_{y}+E_{y} 2^{23} \approx R-\frac{1}{2}\left(M_{x}+E_{x} 2^{23}\right)
$$
还记得我们前面那个“浮点数 32bits 二进制整型算式” $$
M+E * 2^{23}
$$ 吗？假设，浮点数 x 的 32bits 的整型公式是：$$
I_{x}=M_{x}+E_{x} 2^{23}
$$，那么上面的公式就可以写成：$$
I_{y} \approx R-\frac{1}{2} I_{x}
$$



### 代码分析

```c
i  = * ( long * ) &y; // evil floating point bit level hacking
```

这行代码就是把一个浮点数的 32bits 的二进制转成整型。也就是，前面我们例子里说过的，3.14 的 32bits 的二进制是：01000000010010001111010111000011，整型是：1078523331。即 y = 3.14，i = 1078523331。

```c
i  = 0x5f3759df - ( i >> 1 );  // what the fuck? 
```

也就是我们上面推导出来的那个公式：
$$
I_{y} \approx R-\frac{1}{2} I_{x}
$$
代码里的 R = 0x5f3759df。

我们又知道，$$
\mathrm{R}=\frac{3}{2}(127-\sigma) 2^{23}
$$，把代码中的那个魔数代入，就可以计算出来：σ= 0.0450465 。这个数是个神奇的数字，这个数是怎么算出来的，现在还没人知道。不过，我们先往下看后面的代码：

```c

    x2 = number * 0.5F;
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );  // 1st iteration 
    // 2nd iteration, this can be removed
    // y  = y * ( threehalfs - ( x2 * y * y ) ); 
```

这段代码相当于下面这个公式：
$$
I_{y},=I_{y}\left(1.5-0.5 x I_{y}^{2}\right)
$$
![image-20210109185418876](/Users/colinknight/Library/Application Support/typora-user-images/image-20210109185418876.png)

首先，初始值为 X0，然后找到 X0 所对应的 Y0（把 X0 代入公式得到 Y0 = f(X0)），然后在（X0,Y0）这个点上做一个切线，得到与 X 轴交汇的 X1。再用 X1 做一次上述的迭代，得到 X2，就这样一直迭代下去，一直找到，y = 0 时，x 的值。牛顿法的通用公式是：
$$
x_{n+1}=x_{n}-\frac{f\left(x_{n}\right)}{f^{\prime}\left(x_{n}\right)}
$$

$$
\begin{aligned}
&\text { 于是, 对于 } y=\frac{1}{\sqrt{x}} \text { 来说，对固定的 } \times \text { (常数) }, \text { 我们求 } \text { y 使得 } \frac{1}{y^{2}}-x=0, f(y)=\\
&\frac{1}{y^{2}}-x, f^{\prime}(y)=\frac{-2}{y^{3}} \text { 。 注意： } f^{\prime}(y) \text { 是 } f(y) \text { 关于 } \mathrm{y} \text { 的导数。 }
\end{aligned}
$$

代入上述的牛顿法的通用公式后得到：
$$
y_{n+1}=y_{n}-\frac{\frac{1}{y_{n}^{2}}-x}{\frac{-2}{y_{n}^{3}}}
$$

$$
=\frac{y_{n}\left(3-x y_{n}^{2}\right)}{2}=y_{n}\left(1.5-0.5 x y_{n}^{2}\right)
$$

正好就是我们上面的代码。整个代码是，之前生成的整数操作产生首次近似值后，将首次近似值作为参数送入函数最后两句进行精化处理。代码中的两次迭代正是为了进一步提高结果的精度。但由于《雷神之锤 III》的图形计算中并不需要太高的精度，所以代码中只进行了一次迭代，二次迭代的代码则被注释了。

## 机器学习

### 相关算法
> 对于监督式学习，有如下经典算法。
1. 决策树（Decision Tree）。比如自动化放贷、风控。
2. 朴素贝叶斯分类（Naive Bayesian classification）。可以用于判断垃圾邮件，对新闻的类别进行分类，比如科技、政治、运动，判断文本表达的感情是积极的还是消极的，以及人脸识别等。
3. 最小二乘法（Ordinary Least Squares Regression）。算是一种线性回归。
4. 逻辑回归（Logisitic Regression）。一种强大的统计学方法，可以用一个或多个变量来表示一个二项式结果。它可以用于信用评分、计算营销活动的成功率、预测某个产品的收入等。
5. 支持向量机（Support Vector Machine，SVM）。可以用于基于图像的性别检测，图像分类等。
6. 集成方法（Ensemble methods）。通过构建一组分类器，然后根据它们的预测结果进行加权投票来对新的数据点进行分类。原始的集成方法是贝叶斯平均，但是最近的算法包括纠错输出编码、Bagging 和 Boosting。
> 对于非监督式的学习，有如下经典算法。
1. 聚类算法（Clustering Algorithms）。聚类算法有很多，目标是给数据分类。
2. 主成分分析（Principal Component Analysis，PCA）。PCA 的一些应用包括压缩、简化数据，便于学习和可视化等。
3. 奇异值分解（Singular Value Decomposition，SVD）。实际上，PCA 是 SVD 的一个简单应用。在计算机视觉中，第一个人脸识别算法使用 PCA 和 SVD 来将面部表示为“特征面”的线性组合，进行降维，然后通过简单的方法将面部匹配到身份。虽然现代方法更复杂，但很多方面仍然依赖于类似的技术。
4. 独立成分分析（Independent Component Analysis，ICA）。ICA 是一种统计技术，主要用于揭示随机变量、测量值或信号集中的隐藏因素。
> 上面的这些相关算法来源自博文《The 10 Algorithms Machine Learning Engineers Need to Know》。
### 相关推荐

> 学习机器学习有几个课是必须要上的，具体如下。
1. 吴恩达教授（Andrew Ng）在 [Coursera](https://www.coursera.org/learn/machine-learning) 上的机器学习课程非常棒。我强烈建议从此入手。对于任何拥有计算机科学学位的人，或是还能记住一点点数学的人来说，都非常容易入门。这个斯坦福大学的课程后面是有作业的，请尽量拿满分。另外，网易公开课上也有该课程。
2. 卡内基梅隆大学计算机科学学院汤姆·米切尔（Tom Mitchell）教授的机器学习课程，这里有[英文原版视频和课件 PDF](http://www.cs.cmu.edu/~tom/10701_sp11/lectures.shtml) 。汤姆·米切尔是全球 AI 界顶级大牛，在机器学习、人工智能、认知神经科学等领域都有建树，撰写了机器学习方面最早的教科书之一[《机器学习》](https://item.jd.com/10131321.html)，被誉为入门必读图书。
3. 加利福尼亚理工学院亚瑟·阿布·穆斯塔法（Yaser Abu-Mostafa）教授的 [Learning from Data](http://work.caltech.edu/lectures.html) 系列课程 。本课程涵盖机器学习的基本理论和算法，并将理论与实践相结合，更具实践指导意义，适合进阶。
> 除了上述的那些课程外，下面这些资源也很不错。
4. YouTube 上的 Google Developers 的 [Machine Learning Recipes with Josh Gordon](https://www.youtube.com/playlist?list=PLOU2XLYxmsIIuiBfYad6rFYQU_jL2ryal) 。这 9 集视频，每集不到 10 分钟，从 Hello World 讲到如何使用 TensorFlow，值得一看。
5. 还有 [Practical Machine Learning Tutorial with Python Introduction](https://pythonprogramming.net/machine-learning-tutorial-python-introduction/) 上面一系列的用 Python 带着你玩 Machine Learning 的教程。
6. Medium 上的 [Machine Learning - 101](https://medium.com/machine-learning-101) 讲述了好多我们上面提到过的经典算法。
7. 还有，Medium 上的 [Machine Learning for Humans](https://medium.com/machine-learning-for-humans)，不仅提供了入门指导，更介绍了各种优质的学习资源。
8. [杰森·布朗利（Jason Brownlee）博士的博客](https://machinelearningmastery.com/blog/) 也是非常值得一读，其中好多的 “How-To”，会让你有很多的收获。
9. [i am trask](http://iamtrask.github.io/) 也是一个很不错的博客。
10. 关于 Deep Learning 中神经网络的学习，推荐 YouTube 介绍视频 [Neural Networks](https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi)。
11. 用 Python 做自然语言处理[Natural Language Processing with Python](http://www.nltk.org/book/)。
12. 以及 GitHub 上的 [Machine Learning 和 Deep Learning](https://github.com/ujjwalkarn/Machine-Learning-Tutorials) 的相关教程列表。
> 此外，还有一些值得翻阅的图书。
13. [《机器学习》](https://cs.nju.edu.cn/zhouzh/zhouzh.files/publication/MLbook2016.htm)，南京大学周志华教授著。它是一本机器学习方面的入门级教科书，适合本科三年级以上的学生学习。这本书如同一张地图一般，让你能“观其大略”，了解机器学习的各个种类、各个学派，其覆盖面与同类英文书籍相较不遑多让。
14. [A Course In Machine Learning](http://ciml.info/)，马里兰大学哈尔·道姆（Hal Daumé III）副教授著。 这本书讲述了几种经典机器学习算法，包括决策树、感知器神经元、kNN 算法、K-means 聚类算法、各种线性模型（包括对梯度下降、支持向量机等的介绍）、概率建模、神经网络、非监督学习等很多主题，还讲了各种算法使用时的经验技巧，适合初学者学习。此外，官网还提供了免费电子版。
15. [Deep Learning](https://www.deeplearningbook.org/)，麻省理工学院伊恩·古德费洛（Ian Goodfellow）、友华·本吉奥（Yoshua Benjio）和亚伦·考维尔（Aaron Courville）著。这本书是深度学习专题的经典图书。它从历史的角度，将读者带进深度学习的世界。深度学习使用多层的（深度的）神经元网络，通过梯度下降算法来实现机器学习，对于监督式和非监督式学习都有大量应用。如果读者对该领域有兴趣，可以深入阅读本书。本书官网提供免费电子版，但不提供下载。实体书（英文原版或中文翻译版）可以在网上买到。
16. [Reinforcement Learning](http://www.freetechbooks.com/reinforcement-learning-an-introduction-second-edition-draft-t1282.html)，安德鲁·巴托（Andrew G.Barto）和理查德·萨顿（Richard S. Sutton）著。这本书是强化学习（Reinforcement Learning）方面的入门书。它覆盖了马尔可夫决策过程（MDP）、Q-Learning、Sarsa、TD-Lamda 等方面。这本书的作者是强化学习方面的创始人之一。强化学习（结合深度学习）在围棋程序 AlphaGo 和自动驾驶等方面都有着重要的应用。
17. [Pattern Recognition and Machine Learning](https://www.amazon.com/Pattern-Recognition-Learning-Information-Statistics/dp/0387310738) ，微软剑桥研究院克里斯托夫·比肖普（Christoph M. Bishop）著。这本书讲述了模式识别的技术，包括机器学习在模式识别中的应用。模式识别在图像识别、自然语言处理、控制论等多个领域都有应用。日常生活中扫描仪的 OCR、平板或手机的手写输入等都属于该领域的研究。










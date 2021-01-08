 


# 技术基础

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












---
title: 'python 解压&压缩文件'
date: 2019-12-02 22:06:09
tags: [Programming Language]
published: true
hideInList: false
feature: /post-images/python-jie-ya-andya-suo-wen-jian.png
---
# python解压&压缩文件

```python
def zipDir(dirpath,outFullName):
    """
    压缩指定文件夹
    :param dirpath: 目标文件夹路径
    :param outFullName: 压缩文件保存路径+xxxx.zip
    :return: 无
    """
    zip = zipfile.ZipFile(outFullName,"w",zipfile.ZIP_DEFLATED)
    for path,dirnames,filenames in os.walk(dirpath):
        # 去掉目标跟路径，只对目标文件夹下边的文件及文件夹进行压缩
        fpath = path.replace(dirpath,'')

        for filename in filenames:
            zip.write(os.path.join(path,filename),os.path.join(fpath,filename))
    zip.close()
```



```python
def zip_ya(start_dir):
    start_dir = start_dir  # 要压缩的文件夹路径
    file_news = start_dir + '.zip'  # 压缩后文件夹的名字

    z = zipfile.ZipFile(file_news, 'w', zipfile.ZIP_DEFLATED)
    for dir_path, dir_names, file_names in os.walk(start_dir):
        f_path = dir_path.replace(start_dir, '')  # 这一句很重要，不replace的话，就从根目录开始复制
        f_path = f_path and f_path + os.sep or ''  # 实现当前文件夹以及包含的所有文件的压缩
        for filename in file_names:
            z.write(os.path.join(dir_path, filename), f_path + filename)
            z.close()
            return file_news

```

```python
import zipfile #引入zip管理模块
import os
import sys #引入sys模块，获取脚本所在目录

#定义一个函数，递归读取absDir文件夹中所有文件，并塞进zipFile文件中。参数absDir表示文件夹的绝对路径。
def writeAllFileToZip(absDir,zipFile):
    for f in os.listdir(absDir):
        absFile=os.path.join(absDir,f) #子文件的绝对路径
        if os.path.isdir(absFile): #判断是文件夹，继续深度读取。
            relFile=absFile[len(os.getcwd())+1:] #改成相对路径，否则解压zip是/User/xxx开头的文件。
            zipFile.write(relFile) #在zip文件中创建文件夹
            writeAllFileToZip(absFile,zipFile) #递归操作
        else: #判断是普通文件，直接写到zip文件中。
            relFile=absFile[len(os.getcwd())+1:] #改成相对路径
            zipFile.write(relFile)
    return
    
zipFilePath=os.path.join(sys.path[0],"test.zip") 
#先定义zip文件绝对路径。sys.path[0]获取的是脚本所在绝对目录。
#因为zip文件存放在脚本同级目录，所以直接拼接得到zip文件的绝对路径。

zipFile=zipfile.ZipFile(zipFilePath,"w",zipfile.ZIP_DEFLATED) 
#创建空的zip文件(ZipFile类型)。参数w表示写模式。zipfile.ZIP_DEFLATE表示需要压缩，文件会变小。ZIP_STORED是单纯的复制，文件大小没变。

absDir=os.path.join(sys.path[0],"testDir") 
#要压缩的文件夹绝对路径。

writeAllFileToZip(absDir,zipFile) #开始压缩。如果当前工作目录跟脚本所在目录一样，直接运行这个函数。
#执行这条压缩命令前，要保证当前工作目录是脚本所在目录(absDir的父级目录)。否则会报找不到文件的错误。
print("压缩成功")

# 如果当前工作目录是动态的(比如你把脚本拖到终端运行时，工作目录不一定是脚本所在目录)，需要动态调整工作目录
cwd=os.getcwd() #获取当前工作目录
os.chdir(os.path.dirname(absDir))  #修改当前工作目录，指向要压缩文件夹absDir的父级目录。
writeAllFileToZip(absDir,zipFile) #开始压缩
os.chdir(cwd) #回到初始工作目录
print("压缩成功")

```

```python 
import zipfile

# zip压缩
z = zipfile.ZipFile('ss.zip', 'w', zipfile.ZIP_STORED) #打包，zipfile.ZIP_STORED是默认参数
# z = zipfile.ZipFile('ss.zip', 'w', zipfile.ZIP_DEFLATED) #压缩
z.write('ss2')
z.write('ss1')
z.close()

# zip解压
z = zipfile.ZipFile('ss.zip', 'r')
z.extractall(path=r"C:\Users\Administrator\Desktop")
z.close()

```

```python
import tarfile

# tar压缩
tar = tarfile.open('your.tar', 'w')
tar.add('/Users/wupeiqi/PycharmProjects/bbs2.log', arcname='bbs2.log')
tar.add('/Users/wupeiqi/PycharmProjects/cmdb.log', arcname='cmdb.log')
tar.close()

# tar解压
tar = tarfile.open('your.tar', 'r')
tar.extractall()  # 可设置解压地址
tar.close()

import zipfile
import os 
if __name__=='__main__':
    source_path=r'E:\2d_whole_img_529\label_5_29\5_29' 
    for (root1, dirs1, files1) in os.walk(source_path):
        for filename1 in files1:
            imagepath1=os.path.join(root1,filename1)
            print(imagepath1)
            try:
                z = zipfile.ZipFile(imagepath1, 'r')
                z.extractall(path=r"E:\2d_whole_img_529\all")
                z.close()
            except:
                pass


```

```python
#coding:utf-8
import os  
'''
环境：windows10 
压缩工具：7z.exe
实现语言：python
语言版本：2.7
*****网上提供了一堆坑人的解压方法，本想省点事快速搞定 奶奶个腿的  都怪自己太懒反倒浪费了更多时间****
这里只针对压缩和解压缩文件
在这里遇到的主要麻烦就是含有空格的路径的处理比较麻烦，开始找了很久都没有搞定
参考：http://www.docin.com/p-631199577.html 虽然是关于C#解压 但是方法都相同，
没有细看只看了自己需要的
压缩：
压缩的时候chdir最好切到需要压缩的文件夹下，不然cmd会很长，切记在遇到空格的时候使用双引号括起来
如果文件发生变动，那么再次压缩的时候7z会自动更新
解压缩
解压缩的时候chdir最好切到7z.exe目录下，这样相对而言cmd会短一些，也会避免一些错误
如果解压命令使用 “e” 将失去目录关系
 -aos -r ：表示如果已经被解压就不再解压并且不询问。
 解压缩，如果被解压的文件发生变动，解压缩元旦发现已经有需要解压的同名文件夹则不会更新直接跳过不解压
 如果有方法请留言告知 谢谢
'''
sign=False;#标记是解压还是压缩
if sign:
folder_name=r"C:\xxxxxxxxxxx\New folder";\\需要压缩的文件位置
os.chdir(folder_name)#切换到相应的目录下
#压缩
#1.txt 2.txt是folder_name目录需要压缩的文件列表
#C:\\xxxxxxxxxxx\\\"New folder\"\\c.7z 存储位置及压缩文件的名称
cmd = r"C:\\\"Program Files\"\\7-Zip\\7z.exe a C:\\xxxxxxxxxxx\\\"New folder\"\\c.7z 1.txt 2.txt";
print cmd;
os.system(cmd)
else:
folder_name=r"C:\Program Files\7-Zip"#7z.exe位置
os.chdir(folder_name)
# 解压
rar_path = "C:\\xxxxxxxxxxx\\New folder (2)\\c.rar";
un_path,name = os.path.splitext(rar_path);
un_path = '"{}"'.format(un_path);
cmd = '7z.exe x "{}" -o{} -aos -r'.format(rar_path,un_path);
print cmd;
os.system(cmd)

```

```python
Python调用7zip命令实现文件批量解压

1.输入压缩文件所在的路径

2.可以在代码中修改解压到的文件路径和所需要解压的类型，列入，解压文件夹下面所有的mp4格式的文件

3.cmd 指的就是Python调用dos命令 ，紧跟着的x -r这些全是参考7zip使用书册，及抽取文件夹下所有的以mp4结尾的文件，把文件放入e盘，测试解压文件夹下的new文件夹

# 调用7z命令批量解压文件

import os

folder_name = input("请输入文件夹：")

os.chdir(folder_name)

file_names = os.listdir("./")

for name in file_names:

    print("是不是文件：", os.path.isfile(name))

    if os.path.isfile(name):

        name = os.path.abspath(name)

        # 返回一个元组，元组第二个元素是扩展名

        if os.path.splitext(name)[1] == ".zip":

            cmd = '\"C:\\Program Files\\7-Zip\\7z.exe\" x \"{0}\" -oe:/测试解压/new *.mp4 -r'.format(name)

            os.popen(cmd)
```

```python
#coding=utf-8
#甄码农python代码
#使用zipfile做目录压缩，解压缩功能
import os,os.path
import zipfile
def zip_dir(dirname,zipfilename):
  filelist = []
  if os.path.isfile(dirname):
    filelist.append(dirname)
  else :
    for root, dirs, files in os.walk(dirname):
      for name in files:
        filelist.append(os.path.join(root, name))
  zf = zipfile.ZipFile(zipfilename, "w", zipfile.zlib.DEFLATED)
  for tar in filelist:
    arcname = tar[len(dirname):]
    #print arcname
    zf.write(tar,arcname)
  zf.close()
def unzip_file(zipfilename, unziptodir):
  if not os.path.exists(unziptodir): os.mkdir(unziptodir, 0777)
  zfobj = zipfile.ZipFile(zipfilename)
  for name in zfobj.namelist():
    name = name.replace('\\','/')
    if name.endswith('/'):
      os.mkdir(os.path.join(unziptodir, name))
    else:
      ext_filename = os.path.join(unziptodir, name)
      ext_dir= os.path.dirname(ext_filename)
      if not os.path.exists(ext_dir) : os.mkdir(ext_dir,0777)
      outfile = open(ext_filename, 'wb')
      outfile.write(zfobj.read(name))
      outfile.close()
if __name__ == '__main__':
  zip_dir(r'E:/python/learning',r'E:/python/learning/zip.zip')
  unzip_file(r'E:/python/learning/zip.zip',r'E:/python/learning2')
   
# 运行后在E:/python/learning目录下生成zip.zip压缩文件，同时在E:/python目录下解压缩zip.zip文件到learning2目录。
```

```python

Python调用7zip命令实现文件批量解压

1.输入压缩文件所在的路径

2.可以在代码中修改解压到的文件路径和所需要解压的类型，列入，解压文件夹下面所有的mp4格式的文件

3.cmd 指的就是Python调用dos命令 ，紧跟着的x -r这些全是参考7zip使用书册，及抽取文件夹下所有的以mp4结尾的文件，把文件放入e盘，测试解压文件夹下的new文件夹

# 调用7z命令批量解压文件
import os

folder_name = input("请输入文件夹：")
os.chdir(folder_name)
file_names = os.listdir("./")
for name in file_names:
    print("是不是文件：", os.path.isfile(name))
    if os.path.isfile(name):
        name = os.path.abspath(name)
        # 返回一个元组，元组第二个元素是扩展名
        if os.path.splitext(name)[1] == ".zip":
            cmd = '\"C:\\Program Files\\7-Zip\\7z.exe\" x \"{0}\" -oe:/测试解压/new *.mp4 -r'.format(name)
            os.popen(cmd)
```


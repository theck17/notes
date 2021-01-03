---
title: 'python字符串操作'
date: 2019-07-11 11:58:48
tags: [Programming Language]
published: true
hideInList: false
feature: /post-images/python-zi-fu-chuan-cao-zuo.png
---
# 字符串基本操作
## 切片
```python
# str[beg:end]（下标从 0 开始）从下标为beg开始算起，切取到下标为 end-1 
str = 'Keep on going never give up'
print(str[3:6])    # p o
# str[beg:end:step]
# 取 [beg, end) 之间的元素，每隔 step 个取一个
print(str[2:7:2])  # e n 
```
## 原始字符串
```python
#在字符串前加 r/R
#所有的字符串都是直接按照字面的意思来使用，没有转义特殊或不能打印的字符
print(r'\n')   # \n
```
## 字符串重复
```python
# str * n, n * str
# n 为一个 int 数字
str = "colinknight"
print(str*2)  # colinknightcolinknight
print(2*str)  # colinknightcolinknight
```
## in
```python
#in
str = ' python'
print('p' in str)  # True
print('py' in str)   # True
print('py' not in str) # False
```
# 字符串常用函数
## 去空格
```python
str = ' python str '
print(str)  #  python str
# 去首尾空格
print(str.strip()) # python str
# 去左侧空格
print(str.lstrip()) # python str
# 去右侧空格
print(str.rstrip()) #  python str
```
## 分隔字符串
```python
str = ' 1 , 2 , 3 , 4 , 5 , '
# 默认使用空格分隔
print(str.split())   # ['1', ',', '2', ',', '3', ',', '4', ',', '5', ',']
# 指定使用空格进行分隔，首尾如果有空格，则会出现在结果中
print(str.split(' ')) # ['', '1', ',', '2', ',', '3', ',', '4', ',', '5', ',', '']
# 指定其他字符串进行分隔
print(str.split(',')) # [' 1 ', ' 2 ', ' 3 ', ' 4 ', ' 5 ', ' ']
print(str.split('3 ,')) # [' 1 , 2 , ', ' 4 , 5 , ']
str = 'mississippi'
print(str.rstrip('ip')) # mississ
# 取行, python 中把 "\r"，"\n"，"\r\n"，作为行分隔符
str = 'ab c\n\nde fg\rkl\r\n'
print(str.splitlines())     # ['ab c', '', 'de fg', 'kl']
print(str.splitlines(True))  # ['ab c\n', '\n', 'de fg\r', 'kl\r\n']
```
## 拼接字符串
```python
# str.join()方法用于将序列中的元素以指定的字符连接生成一个新的字符串。
str = '-'
seq = ("a", "b", "c"); # 字符串序列
print(str.join(seq))  # 'a-b-c'
```
## 统计字符串里某个字符出现的次数
```python
# str.count(sub, start= 0,end=len(string))
str = "Keep on going never give up"
print(str.count('i', 0, 5))  # 0
print(str.count('e'))  # 5
```
## 检测字符串中是否包含子字符串
```python
# str.find(str, beg=0, end=len(string))
# 如果包含子字符串返回开始的索引值，否则返回-1。
str1 = "Keep on going never give up"
str2 = "going"
print(str1.find(str2))      # 8
print(str1.find(str2, 10))  # -1
print(str1.find(str2, 40))  # -1
# str.index(str, beg=0, end=len(string))
# 如果包含子字符串返回开始的索引值，否则抛出异常。
print(str1.index(str2))   # 8
print(str1.index(str2, 5)) # 8
#print(str1.index(str2, 40))
# Traceback (most recent call last):
#   File "test.py", line 8, in
#   print str1.index(str2, 40);
#   ValueError: substring not found
# shell returned 1

# str.rfind(str, beg=0, end=len(string))
# str.rindex(str, beg=0, end=len(string))
```
## 判断字符串是否以指定前缀、后缀结尾
```python
# str.startswith(str, beg=0,end=len(string))
# 检查字符串以指定子字符串开头，如果是则返回 True，否则返回 False
str = "Keep on going never give up"
print(str.startswith( 'Keep' ))       # True
print(str.startswith( 'on', 2, 4 ))    # False
print(str.startswith( 'keepd', 2, 4 ))  # False

# str.endswith(suffix[, start[, end]])
# 以指定后缀结尾返回True，否则返回False
suffix = "colin"
print(str.endswith(suffix))         # False
print(str.endswith(suffix,20))      # False
suffix = "is"
print(str.endswith(suffix, 2, 4))   # False
print(str.endswith(suffix, 2, 6))   # False
```
## 根据指定的分隔符将字符串进行分割
```python
# str.partition(del)
# 返回一个3元的元组，第一个为分隔符左边的子串，第二个为分隔符本身，第三个为分隔符右边的子串。
str = "http://www.baidu.com/"
print(str.partition("://"))  # ('http', '://', 'www.baidu.com/')
# string.rpartition(str)   从右边开始
```
## 替换字符串
```python
# str.replace(old, new[, max])
# 字符串中的 old（旧字符串） 替换成 new(新字符串)，如果指定第三个参数max，则替换不超过 max 次。
str = "Keep on going is never give up"
print(str.replace("is", "was"))     # Keep on going was never give up
print(str.replace("is", "was", 3))  # Keep on going was never give up
# str.expandtabs(tabsize=8)
# 把字符串中的 tab 符号('\t')转为空格，tab 符号('\t')默认的空格数是 8
```
## 检测字符串组成
```python
# 检测数字
str.isdigit()    # 检测字符串是否只由数字组成
str.isnumeric()  # 检测字符串是否只由数字组成,这种方法是只针对unicode对象
str.isdecimal()  # 检查字符串是否只包含十进制字符。这种方法只存在于unicode对象
# 检测字母
str.isalpha()   # 检测字符串是否只由字母组成
# 检测字母和数字
str.isalnum()   # 检测字符串是否由字母和数字组成
# 检测其他
str.isspace()   # 检测字符串是否只由空格组成
str.islower()   # 检测字符串是否由小写字母组成
str.isupper()   # 检测字符串中所有的字母是否都为大写
str.istitle()   # 检测字符串中所有的单词拼写首字母是否为大写，且其他字母为小写
```
## 字符串处理
```python
str.capitalize()   # 将字符串的第一个字母变成大写,其他字母变小写
str.lower()        # 转换字符串中所有大写字符为小写
str.upper()        # 将字符串中的小写字母转为大写字母
str.swapcase()     # 对字符串的大小写字母进行转换
max(str)    # 返回字符串 str 中最大的字母
min(str)    # 返回字符串 str 中最小的字母
len(str)    # 返回字符串的长度
str(arg) # 将 arg 转换为 string
```
# 格式化输出
## 居中填充
```python
# str.center(width[, fillchar])
# 返回一个原字符串居中,并使用空格填充至长度 width 的新字符串。默认填充字符为空格
str = "Keep on going never give up"
print(str.center(40, 'a'))   #aaaaaaKeep on going never give upaaaaaaa
```
## 靠右填充
```python
# str.zfill(width)
# 返回指定长度的字符串，原字符串右对齐，前面填充0
str = "Keep on going never give up"
print(str.zfill(40))   # 0000000000000Keep on going never give up
```
## 输出格式
```python
print("My name is %s and weight is %d kg!" % ('colin', 23))
#0000000000000Keep on going never give up
print('%(language)s has %(number)03d quote types.' % {"language": "Python", "number": 2})
#Python has 002 quote types.
# Python has 002 quote types.
# str.format(*args, **kwargs)
print('{0}, {1}, {2}'.format('a', 'b', 'c'))  # a, b, c
print('{1}, {0}, {2}'.format('a', 'b', 'c'))  # b, a, c
```




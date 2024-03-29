/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-07-23 21:25:33
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <bitset>           //STL 位集容器
#include <cctype>          //字符处理
#include <cerrno>          //定义错误码 
#include <cfloat>          //浮点数处理 
#include <ciso646>         //对应各种运算符的宏
#include <climits>         //定义各种数据类型最值的常量
#include <clocale>         //定义本地化函数
#include <cmath>           //定义数学函数 
#include <complex>         //复数类 
#include <csignal>         //信号机制支持 
#include <csetjmp>         //异常处理支持 
#include <cstdarg>         //不定参数列表支持
#include <cstddef>         //常用常量
#include <cstdio>          //定义输入／输出函数
#include <cstdlib>         //定义杂项函数及内存分配函数
#include <cstring>         //字符串处理
#include <cwchar>          //宽字符处理及输入／输出
#include <cwctype>         //宽字符分类
#include <deque>           //STL 双端队列容器
#include <exception>       //异常处理类
#include <fstream>         //文件输入／输出
#include <functional>      //STL 定义运算函数（代替运算符）
#include <limits>          //定义各种数据类型最值常量
#include <list>            //STL 线性列表容器
#include <map>             //STL 映射容器
#include <locale>          //本地化特定信息
#include <memory>          //STL通过分配器进行的内存分配
#include <new>             //动态内存分配
#include <numeric>         //STL常用的数字操作
#include <iostream>        //数据流输入／输出
#include <istream>         //基本输入流
#include <iterator>        //STL迭代器
#include <ostream>         //基本输出流
#include <queue>           //STL 队列容器
#include <set>             //STL 集合容器
#include <sstream>         //基于字符串的流
#include <stack>           //STL 堆栈容器
#include <stdexcept>       //标准异常类
#include <streambuf>       //底层输入／输出支持
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};

int main(){
    return 0;
}

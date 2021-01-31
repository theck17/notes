/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-14 21:50:58
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
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
    double getMed(vector<int>a1, vector<int>a2, int n1, int n2)
    {
        int begin1 = 0, end1 = n1;

        while(begin1 <= end1)
        {
            int i1 = (begin1 + end1) / 2;
            int i2 = (n1 + n2 + 1) / 2 - i1;

            int min1 = (i1 == n1)?INT_MAX:a1[i1];
            int max1 = (i1 == 0)?INT_MIN:a1[i1 - 1];

            int min2 = (i2 == n2)?INT_MAX:a2[i2];
            int max2 = (i2 == 0)?INT_MIN:a2[i2 - 1];

            if(max1 <= min2 && max2 <= min1)
            {
                if((n1 + n2) % 2 == 0)
                    return ((double)max(max1, max2) + min(min1, min2)) / 2;
                else
                    return (double)max(max1, max2);
            }
            else if(max1 > min2)
                end1 = i1 - 1;
            else 
                begin1 = i1 + 1;
        }
        
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums.size();
        if(n1==0)
        {
            if(n2%2)
                return nums2[n2/2];
            else
                return (double)(nums2[n2/2-1]+nums2[n2/2])/2;
        }
        
        if(n2==0)
        {
            if(n1%2)
                return nums1[n1/2];
            else
                return (double)(nums1[n1/2-1]+nums1[n1/2])/2;
        }
        
        if(n1<n2)
            return getMed(nums1,nums2,n1,n2);
        else
            return getMed(nums2,nums1,n2,n1);
        
    }
};2


int main(){
    return 0;
}

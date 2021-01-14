/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-14 22:16:34
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <bitset>           //STL 位集容器
#include <cctype>          //字符处理
#include <cerrno>          //定义错误码 
#include <cfloat>          //浮点数处理 
#include <ciso646>         //对应各种运算符的宏
#include <locale>          //本地化特定信息
#include <memory>          //STL通过分配器进行的内存分配
#include <new>             //动态内存分配
#include <iostream>        //数据流输入／输出
#include <istream>         //基本输入流
#include <iterator>        //STL迭代器
#include <set>             //STL 集合容器
#include <sstream>         //基于字符串的流
#include <stack>           //STL 堆栈容器
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        if(nums.size()==0)
            return 0;
        for(int j=i+1;j<nums.size();)
          { if(nums[i]==nums[j])
              j++;
            else
              { i++;
                nums[i]=nums[j];
              }
          }
      return i+1;  
    }
};




int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-18 21:24:51
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
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
    int searchInsert(vector<int>& nums, int target) {

        if(nums[0] > target) return 0;
        
        int size = nums.size();

        for(int i=0; i<size; i++) {
            if(nums[i] >= target) {
                return i;
            }
        }

        return size;
    }
};



int main(){
    return 0;
}

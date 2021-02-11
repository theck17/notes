/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-10 20:47:38
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
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target)
                r--;
            else if (sum < target)
                l++;
            else
                return { l + 1, r + 1 };
        }
        return {}; 
    }
};



int main(){
    return 0;
}

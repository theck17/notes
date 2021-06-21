/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-06-21 19:07:40
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <streambuf>       //底层输入／输出支持
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int size_n = nums.size();
        vector<string> res;
        if ( 0 == size_n) return res;
        for (int i = 0; i < size_n;) {
            int start = i, end = i;
            while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
            if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else res.push_back(to_string(nums[start]));
            i = end+1;
        }
        return res;
    }
};

int main(){
    return 0;
}

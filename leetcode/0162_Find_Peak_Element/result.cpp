/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-06-03 21:33:05
 *   Description   ：
 */
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // edge case - only one item
        if (nums.size() == 1) return 0;
        // peak is first item
        if (nums[0] > nums[1]) return 0;
        // peak is last item
        if (nums.back() > nums[nums.size()-2]) return nums.size()-1;
        // iterate to find peak
        for (int i=0; i<nums.size(); i++) 
            if ((nums[i] > nums[max(0,i-1)]) && (nums[i] > nums[i+1])) return i;
        return -1;
    }
};




int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-06-28 19:57:27
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int first = nums[0];
        for(int i = 1; i<nums.size();i++) {
            first = first ^ nums[i];
        }
        return first;
    }
};



int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-22 19:54:53
 *   Description   ：
 */
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        
        if(lb == nums.end() || lb == ub) return vector<int>{-1, -1};
        
        return vector<int>{(int)(lb - nums.begin()), (int)(ub - nums.begin()) - 1};
    }
};

int main(){
    return 0;
}

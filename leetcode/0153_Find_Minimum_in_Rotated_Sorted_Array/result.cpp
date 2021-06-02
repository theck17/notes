/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-06-01 21:30:49
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0,  right = nums.size() - 1;
        while(left < right) {
            if(nums[left] < nums[right]) 
                return nums[left];

            int mid = (left + right)/2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};




int main(){
    return 0;
}

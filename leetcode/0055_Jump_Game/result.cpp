/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-05 10:10:26
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <vector>          //STL 动态数组容器
using namespace std;


class Solution {
public:
  bool canJump(vector<int> &nums) {
    int max_distance = 0;
    const int target = nums.size() - 1;
    for (int i = 0; i < nums.size() && i <= max_distance; ++i) {
      max_distance = std::max(max_distance, nums[i] + i);
    }
    return target <= max_distance;
  }
};



int main(){
    return 0;
}

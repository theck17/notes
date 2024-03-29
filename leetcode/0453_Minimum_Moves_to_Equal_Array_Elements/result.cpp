/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-07-02 19:53:24
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
       int n = nums.size();
       if(n <= 1)
          return 0;
       int mn = nums[0];
       long sum = nums[0];
       for(int i = 1; i < n; ++i)
       {
           mn = min(mn,nums[i]);
           sum += nums[i];
       }
       return sum -long(mn)*long(n); 
    }
};


int main(){
    return 0;
}

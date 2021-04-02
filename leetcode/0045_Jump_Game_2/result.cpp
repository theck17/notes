/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-29 20:25:27
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <vector>          //STL 动态数组容器
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1001);
        int x = n-1;
        dp[x] = 0;
        int ans = 0;
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i+1; j<min(n, i+1+nums[i]); j++)
            {
                cout<<i<<" "<<nums[i]<<" "<<x<<endl;
                dp[i] = min(1+dp[j], dp[i]);
            }
        }
        for(auto x:dp)
            cout<<x<<" ";
        return dp[0];
    }
};




int main(){
    return 0;
}

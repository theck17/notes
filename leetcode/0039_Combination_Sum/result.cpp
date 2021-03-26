/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-19 19:52:27
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
		// dp vector to store all possible combinations of the target sum
        vector <vector <vector <int>>> dp(target+1);
        dp[0]={{}};
        for(int i:nums)
        {
		// Iterating through all the elements from array nums aka candidates
            for(int j=i;j<=target;j++)
            {
			// Finding all possible ways to achieve sum j from element i
                for(auto v:dp[j-i])
                {
                    v.push_back(i);
                    dp[j].push_back(v);
                }
            }
        }
		// Finally, returning our ans 🙃
        return dp[target];
    }
};



int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-20 18:47:24
 *   Description   ：
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (auto n : nums) sum += n;
        if ((sum + S) % 2 == 1 || S > sum || S < -sum) return 0;
        int newS = (sum + S) / 2;
        vector<int> dp(newS + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = newS; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newS];
    }
};


int main(){
    return 0;
}

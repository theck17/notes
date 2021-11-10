/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-10 19:43:38
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n)); // use to keep the score gap between player1 and player2
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j+i < n; j++) {
                dp[j][j+i] = max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]);
            }
        }
        return dp[0][n-1] >= 0; // player1 get more score points than player2
    }
};

int main(){
    return 0;
}

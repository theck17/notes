/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-03-03 07:44:10
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
       int n = nums.size();
       vector<vector<int>> dp(n, vector<int> (n));
       for(int g = 0; g<n; g++){
           for(int i=0, j=g; j<n; i++, j++){
               int maxval = -1;
               for(int k = i; k<=j; k++){
                   int left = k == i ? 0 : dp[i][k-1];
                   int right = k == j ? 0 : dp[k+1][j];
                   int brust =(i == 0 ? 1 : nums[i-1])*nums[k]*(j == n-1 ? 1 : nums[j+1]);
                   int total = left+ right + brust;
                   maxval = max(maxval, total);
               }
               dp[i][j] = maxval;
           }
       }
       return dp[0][n-1];
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-18 11:13:17
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for (auto &s: strs) {
            int ones = count(s.begin(), s.end(), '1');
            int zeros= s.size()-ones;
            for (int i=m; i>=zeros; i--) 
                for (int j=n; j>=ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
        }
        return dp[m][n];
    }
};

int main(){
    return 0;
}

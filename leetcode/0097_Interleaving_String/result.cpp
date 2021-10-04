/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-04 20:40:37
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = (int)s1.size(), n2 = (int)s2.size(), n3 = (int)s3.size(); 
        if(n1 + n2 != n3) return false;
        
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        
        for(int i2 = 1; i2 <= n2; i2++) dp[0][i2] = dp[0][i2 - 1] && s2[i2 - 1] == s3[i2 - 1];
        for(int i1 = 1; i1 <= n1; i1++) dp[i1][0] = dp[i1 - 1][0] && s1[i1 - 1] == s3[i1 - 1];

        for(int i1 = 1; i1 <= n1; i1++){
            for(int i2 = 1; i2 <= n2; i2++){
                dp[i1][i2] = (dp[i1 - 1][i2] && s1[i1 - 1] == s3[i1 + i2 - 1]) || (dp[i1][i2 - 1] && s2[i2 - 1] == s3[i1 + i2 - 1]);
            }
        }
        
        return dp[n1][n2];  
    }
};

int main(){
    return 0;
}

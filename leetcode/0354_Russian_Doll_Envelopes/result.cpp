/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-25 09:17:36
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), res = 0;
        vector<int> dp(n);
        
        sort(envelopes.begin(), envelopes.end());
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(canRussianDoll(envelopes[j], envelopes[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res + 1;
    }
    
private:
    bool canRussianDoll(vector<int>& a, vector<int>& b) {
        return a[0] < b[0] && a[1] < b[1];
    }
};

int main(){
    return 0;
}

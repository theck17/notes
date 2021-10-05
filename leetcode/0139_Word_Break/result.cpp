/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-05 20:45:03
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i=0;i<=s.size();++i){
            for(int j=0;j<i;++j){
                if(dp[j])
                {
                    if(find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))
                                                    != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
                
            }
        }
        return dp[s.size()];
    }
};

int main(){
    return 0;
}

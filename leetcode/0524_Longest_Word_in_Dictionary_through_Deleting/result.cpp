/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-16 21:37:30
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        string ans;
        for(auto d : dict){
            int i = 0, j = 0;
            while(i < s.size() && j < d.size())
                if(s[i] == d[j])i++, j++;
                else i++;

            if(j == d.size())   // d is a subsequence
                if((d.size() > ans.size()) || (d.size() == ans.size() && d < ans))
                    ans = d;               
        }
        return ans;
    }
};

int main(){
    return 0;
}

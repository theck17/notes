/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-11 10:13:56
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return normalize(s) == normalize(t);
    }
    string normalize(const string& s) {
        char mapping[128] = {};
        string ans = "";
        char nextChr = 'a';
        for (char c : s) {
            if (mapping[c] == 0) {
                mapping[c] = nextChr;
                ++nextChr;
            }
            ans += mapping[c];
        }
        return ans;
    }
};

int main(){
    return 0;
}

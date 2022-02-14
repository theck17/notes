/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-14 16:57:42
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1, prev = 0, ans = 0;
        for (int i = 1; i < s.length(); i++)
            if (s[i] == s[i-1]) curr++;
            else ans += min(curr, prev), prev = curr, curr = 1;
        return ans + min(curr, prev);
    }
};

int main(){
    return 0;
}

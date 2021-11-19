/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-19 21:23:05
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while (s.length() < n)
            s.append(s[i++] - '0', s.back() ^ 3); // binary form of '1' is 011 0001
        return count(s.begin(), s.begin() + n, '1');
    }
};

int main(){
    return 0;
}

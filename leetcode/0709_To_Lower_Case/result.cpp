/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-25 21:46:47
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for (auto& c : s)
            ans += c > 64 && c < 91 ? c + 32 : c;
        return ans;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-22 21:11:51
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> f;
        f.push_back(1);
        for (int i = 1; i <= n; ++i) {
            int t = 0;
            for (int j = 0; j < i; ++j)
                t += f[j] * f[i-j-1];
            f.push_back(t);
        }
        return f.back();
    }
};


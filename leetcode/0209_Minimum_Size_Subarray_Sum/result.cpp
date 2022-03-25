/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-06-09 19:30:14
 *   Description   ：
 */
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& A) {
        int i = 0, n = A.size(), res = n + 1;
        for (int j = 0; j < n; ++j) {
            s -= A[j];
            while (s <= 0) {
                res = min(res, j - i + 1);
                s += A[i++];
            }
        }
        return res % (n + 1);
    }
};



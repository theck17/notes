/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-02 10:09:38
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1, 0);
        for (int i = 1; i <= n; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};

int main(){
    return 0;
}

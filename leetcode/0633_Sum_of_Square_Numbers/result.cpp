/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-22 18:56:20
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++) {
            int t=sqrt(c-i*i);
            if(t*t==c-i*i) return true;
        }
        return false;
    }
};

int main(){
    return 0;
}

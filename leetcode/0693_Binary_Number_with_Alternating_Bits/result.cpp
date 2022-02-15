/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-15 08:12:53
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int d = n&1;
        while ((n&1) == d) {
            d = 1-d;
            n >>= 1;
        }
        return n == 0;
    }
};

int main(){
    return 0;
}

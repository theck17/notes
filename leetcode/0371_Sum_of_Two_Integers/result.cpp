/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-27 21:22:00
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        int trigger = a & b;
        int ret = a ^ b;
        while(trigger)
        {
            int temp = (trigger & 0xffffffff)<<1;
            trigger = temp & ret;
            ret ^= temp;
        }
        return ret;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-28 22:10:23
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        
        while(num%2 == 0) num/=2;
        while(num%3 == 0) num/=3;
        while(num%5 == 0) num/=5;
        
        return num == 1;
    }
};

int main(){
    return 0;
}

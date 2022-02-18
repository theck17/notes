/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-18 10:35:17
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        int counts = 0;
    
        for (int i=1; i*i<=n; ++i) {
            ++ counts;    
        }
        
        return counts;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-02 10:32:57
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n < 2)
            return n;
        int memo[n+1];
        memo[0] = 0;
        memo[1] = 1;
        for(int i=2; i<=n; i++)
            memo[i] = memo[i-1] + memo[i-2];
        return memo[n];
    }
};

int main(){
    return 0;
}

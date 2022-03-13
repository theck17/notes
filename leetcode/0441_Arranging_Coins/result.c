/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-21 10:37:01
 *   Description   ：
 */
int arrangeCoins(int n) {
    long ans = n;
    ans = sqrt(ans * 8 + 1) - 1; 
    return ans >> 1;
}


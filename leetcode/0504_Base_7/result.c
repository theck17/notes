/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-03 20:11:54
 *   Description   ：
 */
char* convertToBase7(int num) {
    // Check negative
    char neg = 0;
    if (num < 0) {
        neg =  1;
        num = -num;
    }

    // Build up tmp and len
    char tmp[32];
    char len = 0;
    
    do {
        tmp[len++] = num%7 + '0';
        num        = num/7;
    } while (num);
    
    // Construct ans
    char  idx = 0;
    char* ans = malloc(len + neg + 1);
    
    if (neg) {
        ans[idx++] = '-';
    }
    
    for (int i = len - 1; i > -1; --i) {
        ans[idx++] = tmp[i];
    }
    
    ans[idx] = NULL;
    
    return ans;
}

int main(){
    return 0;
}

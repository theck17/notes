/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-21 10:56:37
 *   Description   ：
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    int* a = malloc((right - left + 1) * sizeof(int));
    int  c = -1;
    
    for (int i = left; i < right + 1; ++i) {
        int n = i;
        int d = n%10;
        while (n && d && (i%d == 0)) {
            n = n/10;
            d = n%10;
        }

        if (n == 0) a[++c] = i;
    }
    
    *returnSize = c + 1;
    return a;  
}

int main(){
    return 0;
}

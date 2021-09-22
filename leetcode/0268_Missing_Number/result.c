/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-22 19:24:12
 *   Description   ：
 */

int missingNumber(int* nums, int numsSize) {
    int esum = (numsSize - 1) * numsSize / 2;
    int rsum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        rsum += nums[i];
    }
    return (numsSize - rsum + esum);
}
int main(){
    return 0;
}

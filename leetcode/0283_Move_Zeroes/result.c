/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-17 19:33:19
 *   Description   ：
 */

void moveZeroes(int* nums, int numsSize){

    int j=0,i=0;
    
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=0)
            nums[j++] = nums[i];
    }
    
    for(;j<numsSize;j++)
        nums[j] =0;
}

int main(){
    return 0;
}

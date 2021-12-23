/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-23 19:12:46
 *   Description   ：
 */
int totalHammingDistance(int* nums, int numsSize) {
    int i=0,j=0,count=0,distance=0;
    for(;j<32;j++){
        for(i=0,count=0;i<numsSize;i++){
            count+=nums[i]&1;
            nums[i]=nums[i]>>1;
        }
        distance+=count*(numsSize-count);
    }
    return distance;
}

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-20 18:46:25
 *   Description   ：
 */
int findTargetSumWays(int* nums, int numsSize, int S) {
    if(numsSize==1){
        if(nums[0]==S&&nums[0]==-S){
            return 2;
        }
        if(nums[0]==S||nums[0]==-S){
            return 1;
        }
        return 0;
    }
    return findTargetSumWays(&nums[1],numsSize-1,S+nums[0])+findTargetSumWays(&nums[1],numsSize-1,S-nums[0]);
}

int main(){
    return 0;
}

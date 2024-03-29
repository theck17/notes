/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-13 10:59:54
 *   Description   ：
 */
int arrayPairSum(int* nums, int numsSize){
    int i, bucket[20001]={0};
    int Flag=1,reg=0,count=0;
    for(i=0;i<numsSize;i++)
        bucket[nums[i]+10000]++;
    for(i=0;i<20001&&count<numsSize/2;)   // Use count variable can reduce iteration times
    {
        if(bucket[i]>0)
        {
            if(Flag)
            {
                Flag=0;
                reg+=i-10000;
                bucket[i]--;
                count++;
            }
            else
            {
                Flag=1;
                bucket[i]--;
            }
                
        }
        else i++;
    }
    return reg;
}

int main(){
    return 0;
}

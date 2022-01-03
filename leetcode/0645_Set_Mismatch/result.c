/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-03 08:58:57
 *   Description   ：
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int a[10001]={0};
    int *result=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    for(int i=0;i<numsSize;i++)
    {
        if(++a[nums[i]]==2)
        {result[0]=nums[i];}           
    }
    for(int i=1;i<=numsSize;i++)
    {
        if(a[i]==0)
        {result[1]=i;return result;}
    }
    return result;
}

int main(){
    return 0;
}

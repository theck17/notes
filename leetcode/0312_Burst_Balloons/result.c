/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-03-03 07:49:03
 *   Description   ：
 */
int maxCoins(int* nums, int numsSize){
    int *nums1 = (int*)malloc(sizeof(int)*(numsSize+2));
    nums1[0] = nums1[numsSize+1] = 1;
    for(int i = 0; i < numsSize; i++)
        nums1[i+1] = nums[i];
    numsSize += 2;
    int** maxs = (int**)malloc(sizeof(int*)*numsSize);
    for(int i = 0; i < numsSize; i++)
    {
        maxs[i] = (int*)malloc(sizeof(int)*numsSize);
        memset(maxs[i], 0, sizeof(int)*numsSize);
    }
    for(int i = 2; i < numsSize; i++) 
        for(int left = 0; left+i < numsSize; left++)
        {
            int right = left+i;
            for(int j = left+1; j < right; j++)
            {
                int t = maxs[left][j]+maxs[j][right]+nums1[left]*nums1[right]*nums1[j];
                if(t > maxs[left][right])
                    maxs[left][right] = t;
            }
        }
    return maxs[0][numsSize-1];
}

int main(){
    return 0;
}

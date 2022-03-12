/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-25 18:50:51
 *   Description   ：
 */
int search(int* nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        
        if (nums[middle] == target)
            return middle;
        
        else if (nums[middle] < target)
            left = middle + 1;
        
        else
            right = middle - 1;
    }
    return -1;
}


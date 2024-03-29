/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-14 19:32:09
 *   Description   ：
 */
int cmp(const void *a, const void *b) {
    int **aa;
    int **bb;
    
    aa = (int **)a;
    bb = (int **)b;
    
    return ((*aa)[0] + (*aa)[1]) - ((*bb)[0] + (*bb)[1]); 
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    int **arrayOfArray;
    int i;
    int j;
    int count;
    
    if(nums1Size==0 || nums2Size==0 || k < 1) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * nums1Size * nums2Size);
    arrayOfArray = (int **)malloc(sizeof(int *) * nums1Size * nums2Size);
    
    count = 0;
    for(i = 0; i < nums1Size; i++) {
        for(j = 0; j < nums2Size; j++) {
            arrayOfArray[count] = (int *)malloc(sizeof(int) * 2);
            (arrayOfArray[count])[0] = nums1[i];
            (arrayOfArray[count])[1] = nums2[j];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    qsort(&arrayOfArray[0], nums1Size * num2Size, sizeof(int *), cmp);

    if(count < k) {
        *returnSize = count;
    } else {
        *returnSize = k;
    }
    
    return arrayOfArray;
}s


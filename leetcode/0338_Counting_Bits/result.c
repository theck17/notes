/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-02 10:11:45
 *   Description   ：
 */
int* countBits(int n, int* returnSize){
    int *numBitsArray, idx;
    
    *returnSize = n+1;
    numBitsArray = malloc((n + 1) * sizeof(int));
    
    numBitsArray[0] = 0;
    for (idx = 1; idx <= n; idx++)
    {
        numBitsArray[idx] = numBitsArray[idx >> 1] + (idx & 0x01);
    }
    
    return numBitsArray;
}

int main(){
    return 0;
}

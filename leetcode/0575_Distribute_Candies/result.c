/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-28 21:46:43
 *   Description   ：
 */
int distributeCandies(int* candies, int candiesSize) {
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0; i < candiesSize; i++)
    {
        if(candies[i] > max) max = candies[i];
        if(candies[i] < min) min = candies[i];
    }
    int size = max - min + 1;
    int* hashTable = calloc(size,sizeof(int));
    int count = 0;
    for(int i = 0; i < candiesSize && count<candiesSize/2; i++)
    {
        if(hashTable[candies[i]-min] == 0)
        {
            count++;
            hashTable[candies[i]-min]++;
        }
    }
    free(hashTable);
    return(count);
}


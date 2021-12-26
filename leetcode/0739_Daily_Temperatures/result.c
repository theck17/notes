/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-26 17:58:12
 *   Description   ：
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize = TSize;
    int *result = (int *)calloc(TSize, sizeof(int));
    int stack[TSize];
    int stack_size = 0;
    for (int i = 0; i < TSize; i++)
    {
        while (stack_size != 0 && T[i] > T[stack[stack_size - 1]])
        {
            result[stack[stack_size - 1]] = (i - stack[stack_size - 1]);
            stack_size--;
        }
        stack[stack_size++] = i;
    }
    
    return result;
}

int main(){
    return 0;
}

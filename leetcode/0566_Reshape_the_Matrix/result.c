/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-27 21:49:52
 *   Description   ：
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    int nr = numsSize, nc = *numsColSize;        
    if (nr * nc - r * c) {
        *returnSize = nr;
        *returnColumnSizes = numsColSize;
        return nums;
    }
    int **a = calloc(1, sizeof(int *[r]));
    int *sz = *returnColumnSizes = malloc(sizeof(int [r]));
    for (int i = 0, j = 0, x = 0 ; x < nr ; x++) {
        for (int y = 0 ; y < nc ; y++) {
            j >= c ? i++, j = 0 : 0;
            !a[i] ? a[i] = malloc(sizeof(int [c])) : 0;
            sz[i] = c;
            a[i][j++] = nums[x][y];
        }
    }
    *returnSize = r;    
    return a;
}

int main(){
    return 0;
}

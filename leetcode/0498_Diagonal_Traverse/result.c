/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-19 12:31:33
 *   Description   ：
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    
    int m = matrixSize, n; 
    int *a = NULL, r = 0, c = 0;
    int dir = 1;
   
    *returnSize = 0;
    if (!matrix || !matrixSize || !matrixColSize || !*matrixColSize)
        return a;
    
    n = *matrixColSize;
    
    a = malloc(sizeof(int) * m * n);
    *returnSize = m * n;
    for (int i = 0; i < m * n; i++) {
        switch (dir) {
            case 1:
                a[i] = matrix[r][c];
                if (r - 1 >= 0 && c + 1 < n) {
                    r--;
                    c++;
                    break;
                }
                dir = -1;
                if (c + 1 >= n) {
                    r = r + 1;
                } else
                    c++;
                break;
            case -1:
                a[i] = matrix[r][c];
                if (r + 1 < m && c - 1 >= 0) {
                    r++;
                    c--;
                    break;
                }
                dir = 1;
                if (r + 1 >= m) {
                    c = c + 1;
                } else
                    r++;
                break;
        }
    }
    
    return a;

}

int main(){
    return 0;
}

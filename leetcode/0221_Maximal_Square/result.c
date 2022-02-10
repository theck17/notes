/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-10 10:12:33
 *   Description   ：
 */
int min(int a,int b){
	return a>b?b:a;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
	int *dp = (int *)malloc(sizeof(int )*(*matrixColSize+1));
    memset(dp,'\0',sizeof(int )*(*matrixColSize+1));
	int maxlen = 0;
    int prev =0;

	for (int i = 1; i <= matrixSize; i++) {
            for (int j = 1; j <= *matrixColSize; j++) {
				int temp = dp[j];
                if (matrix[i-1][j-1] == '1'){
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    maxlen = maxlen>dp[j]?maxlen:dp[j];
                }else{
					 dp[j]=0;
				}
                prev = temp;
            }
        }
    return maxlen * maxlen;
}

int main(){
    return 0;
}

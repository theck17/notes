/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-18 11:15:32
 *   Description   ：
 */
int* countFunc(char* s){
    int* ret=(int*)calloc(2,sizeof(int));
    for(int i=0;i<strlen(s);i++){
        ret[s[i]-'0']++;
    }
    return ret;
}
int max(int a,int b){
    return a>b?a:b;
}
int findMaxForm(char** strs, int strsSize, int m, int n) {
    int** dp=(int**)malloc((m+1)*sizeof(int*));
    for(int i=0;i<m+1;i++){
        dp[i]=(int*)calloc(n+1,sizeof(int));
    }
    dp[0][0]=0;
    for(int k=0;k<strsSize;k++){
        int* temp=countFunc(strs[k]);
        for(int i=m; i>=temp[0]; --i) {
            for(int j=n; j>=temp[1]; --j) {
                dp[i][j] = max(dp[i][j], dp[i-temp[0]][j-temp[1]]+1);
            }
        }
        free(temp);
    }
    return dp[m][n];
}


int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-30 11:00:20
 *   Description   ：
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    int* result = (int*) malloc(sizeof(int)*2);
    *returnSize=2;
    int len1=0;
    int i=0;
    while(i<ASize){
        len1 = len1+A[i];
        i++;
    }
    // printf("len1 is %d \n",len1);
    i=0;
    int len2=0;
    while(i<BSize){
        len2 = len2+B[i];
        i++;
    }
    // printf("len1 is %d \n",len2);
    int flag;
    int j;
    for(i=0;i<ASize;i++){
        flag=0;
        int temp1 = len1-A[i];
        for(j=0;j<BSize;j++){
            temp1 = temp1+B[j];
            int temp2 = len2-B[j]; 
            temp2 = temp2+A[i];
            if(temp1 == temp2){
                flag=1;
                break;
            }
            temp1 = len1-A[i];
        }
        if(flag==1){
            break;
        }
    }
    result[0] = A[i];
    result[1] = B[j]; 
    return result; 
}

int main(){
    return 0;
}

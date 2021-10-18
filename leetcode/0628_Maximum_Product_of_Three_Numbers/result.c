/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-18 18:38:47
 *   Description   ：
 */
int maximumProduct(int* nums, int numsSize){
int high1=0;
int high2=0;
int high3=0;
int low1=0;
int low2=0;
int low3=0;
int i;
for (i=0; i<numsSize; i++) {
    if (nums[i]>0)
        if (nums[i]>high3) {
            high1=high2;
            high2=high3;
            high3=nums[i];
        } else if (nums[i]>high2) {
            high1=high2;
            high2=nums[i];
        } else if (nums[i]>high1) high1=nums[i];

    if (nums[i]<0)
        if (nums[i]<low3) {
            low1=low2;
            low2=low3;
            low3=nums[i];
        } else if (nums[i]<low2) {
            low1=low2;
            low2=nums[i];
        } else if (nums[i]<low1) low1=nums[i];
}
    
printf("Highs are %d %d %d and lows are %d %d %d\n",
      high3, high2, high1, low1, low2, low3);
if (high3==0) return low3 * low2 * low1;
if ((high3 * low3 * low2) > (high3 * high2 * high1))
    return high3 * low3 * low2;
    else return high3 * high2 * high1;
}
int main(){
    return 0;
}

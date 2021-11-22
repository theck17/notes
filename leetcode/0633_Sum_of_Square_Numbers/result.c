/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-22 18:57:47
 *   Description   ：
 */
bool judgeSquareSum(int c){
    if(c == 1 || c == 0) return 1;
    (long) c;
    long right = (int)sqrt(c);
    long left = 0;
    while(left <= right){
        long cur = left * left + right * right;
        if(cur < c) left ++;
        else if(cur > c) right --;
        else return 1;
    }
    return 0;
}

int main(){
    return 0;
}

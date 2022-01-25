/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-25 22:21:05
 *   Description   ：
 */
int climbStairs(int n){
    int a=1,b=2;
    int res=0;
    if(n==1 || n==2)
            return n;
    for(int i=3;i<=n;i++)
    {
        res=a+b;
        a=b;
        b=res;
    }
    return res;
}

int main(){
    return 0;
}

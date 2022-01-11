/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-11 23:38:13
 *   Description   ：
 */
bool isPerfectSquare(int num){
    int a=1;
    
    while(num>0){
        num-=a;
        a+=2;
    }
    return(num==0);
}

int main(){
    return 0;
}

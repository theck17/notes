/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-20 11:07:15
 *   Description   ：
 */
int addDigits(int num){
        if(num%9 == 0 && num!=0)
        return 9;
        return (num%9);
}

int main(){
    return 0;
}

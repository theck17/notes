/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-15 08:13:37
 *   Description   ：
 */
bool hasAlternatingBits(int n){
    int num1 = 0;
    int num2 = 0;

    while(n != 0)
    {
        num1 = n & 0x01;
        
        n = n >> 1;
        
        num2 = n & 0x01;
        
        if(num1 == num2)
            return false;
    }

    return true;
}

int main(){
    return 0;
}

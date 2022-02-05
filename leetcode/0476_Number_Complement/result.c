/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-05 16:22:16
 *   Description   ：
 */
int findComplement(int num){
    int result = 0;
    for(int i=0; i<32 && num>0; num>>=1, ++i){
        if(num % 2 == 0)
            result += 1<<i;
    }
    return result;
}

int main(){
    return 0;
}

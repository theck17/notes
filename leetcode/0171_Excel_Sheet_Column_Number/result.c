/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-09 09:14:55
 *   Description   ：
 */
int titleToNumber(char* s) {
    int len = strlen(s)-1;
    int sum=0;
    while(len >=0){
        sum += (*s++-64)*pow(26, len--);
    }
    return sum;
}

int main(){
    return 0;
}

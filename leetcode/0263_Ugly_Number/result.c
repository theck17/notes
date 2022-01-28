/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-28 22:11:22
 *   Description   ：
 */
bool isUgly(int num) {
    if(num<=0) return false;
    while(num>1){
    	if(!(num%2)) num/=2;
    	else if(!(num%3)) num/=3;
    	else if(!(num%5)) num/=5;
    	else return false;
    }
    return true;
}

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-02 10:34:19
 *   Description   ：
 */
int fib(int n){
    int pre  = 0;
    int ret  = 0;
    int next = 1;
    int i;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
     
    for (i = 2; i <= n; i++) {
        ret  = pre + next;
        pre  = next;
        next = ret;
    }
    return ret;
}

int main(){
    return 0;
}

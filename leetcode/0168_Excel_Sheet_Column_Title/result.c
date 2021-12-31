/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-31 18:59:41
 *   Description   ：
 */

int getMaxLen(int n)
{
    int i = 0;
    
    while (n > 0) {
        if (n % 26 == 0) {
            n = (n-1) / 26;
        }
        else {
            n /= 26;
        }
        i++;
    }
    
    return i;
}

char * convertToTitle(int n)
{
    char* ret = NULL;
    int len;
    
    len = getMaxLen(n);
    
    ret = (char*)malloc(sizeof(*ret) * (len+1));
    memset(ret, NULL, len+1);    
    
    while (n > 0) {
        --len;
        if (n % 26 == 0) {
            ret[len] = 'Z';
            n = (n-1) / 26;
        }
        else {
            ret[len] = 'A' + (n % 26) - 1;
            n /= 26;
        }
    }
    
    return ret;
}
int main(){
    return 0;
}

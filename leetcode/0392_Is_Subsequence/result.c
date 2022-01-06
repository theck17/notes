/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-06 21:21:23
 *   Description   ：
 */
bool isSubsequence(char* s, char* t) {
    if (*s=='\0'){
        return true;
    }
    while(*s!=*t){
        if(*t=='\0'){
            return false;
        }
        t = t + 1;
    }
    
    
    return isSubsequence(s+1, t+1);
    
}

int main(){
    return 0;
}

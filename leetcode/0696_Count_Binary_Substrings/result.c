/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-14 16:59:05
 *   Description   ：
 */
int countBinarySubstrings(char * s){
    int cur_len = 1, len = strlen(s), pre_len = 0, ret = 0;
    for(int i = 1; i < len; i++){
        if(*(s+i) == *(s+i-1))
            cur_len ++;
        else{
            pre_len = cur_len;
            cur_len = 1;
        }
        if(pre_len >= cur_len)
            ret ++;
    }
    return ret;
}

int main(){
    return 0;
}

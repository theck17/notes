/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-25 09:06:25
 *   Description   ：
 */
int lengthOfLongestSubstring(char * s){
    int chars[128], idx = 128;
    while (idx--) chars[idx] = -1; 
    
    int start = -1, length = 0, localLength;
    size_t c;
    
    while (s[++idx] != '\0') {
        c = (size_t) s[idx];
        if (chars[c] > start) start = chars[c]; 
        
        localLength = idx - start;
        if (length < localLength) length = localLength;
        chars[c] = idx;
    }
    return (start > -1 ? length : idx);
}

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-26 00:39:10
 *   Description   ：
 */
bool isMatch(char * s, char * p){
    char *p0 = NULL, *s0 = NULL;
    while (*s) {
        if (*p == *s || *p == '?') {
            p++; 
            s++;
        }else if (*p == '*') { // save
            p0 = ++p;
            s0 = s;
        }else if (p0 != NULL) { // load
            p = p0;
            s = ++s0;
        }else {
            return false;
        }
    }
    while (*p == '*') p++;
    return !*s && !*p;
}


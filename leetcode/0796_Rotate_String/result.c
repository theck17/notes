/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-11 12:33:03
 *   Description   ：
 */
bool rotateString(char * s, char * goal){
    if(NULL == s || NULL == goal)
        return false;
    
    int lena = strlen(s);
    int lenb = strlen(goal);
    /*length not equal*/
    if(lena != lenb)
        return false;
    
    char *pos = NULL;
    
    char *AA = (char *)malloc((2 * lena +1) *sizeof(char));
    snprintf(AA,2*lena + 1,"%s%s",s,s);
    
    /*whether B is substr of AA*/
    pos = strstr(AA,goal);
    if(pos)
        return true;
    
    return false;
    
}

int main(){
    return 0;
}

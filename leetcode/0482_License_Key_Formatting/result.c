/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-01 09:42:22
 *   Description   ：
 */
char * licenseKeyFormatting(char * S, int K){
    int numChar = 0;
    int repeat = 0;
    
    char* ret;
    
    int i,j;
    
    if (!S) {
        return NULL;
    }
    
    for (i = 0; S[i]; i++) {
        if (isalpha(S[i]) || isdigit(S[i])) {
            numChar++;
        }
    }
     
    ret = (char*)malloc(sizeof(*ret) * (numChar + numChar/K + 1));
    
    repeat =  numChar % K ? numChar % K: K;
    
    for (i = 0, j = 0; S[i]; i++) {
        if (S[i] == '-') {
            continue;
        }
        if (repeat) {
            if (repeat == K && j) {
                ret[j++] = '-';
            }
            ret[j] = toupper(S[i]);
            j++;
            repeat--;
            
            if (!repeat) {
                repeat = K;
            }
        }
    }
    
    ret[j] = '\0';
    
    return ret;
}

int main(){
    return 0;
}

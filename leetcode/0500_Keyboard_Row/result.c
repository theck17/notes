/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-13 19:12:24
 *   Description   ：
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int contains(char *string, char c){
    return strchr(string, tolower(c)) != NULL ? 1 : 0;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    if(words == NULL || wordsSize == 0) return findWords;
    
    char *keyboard[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    
    char  **validWords = (char**)malloc(sizeof(char *) * wordsSize);
    
    int idx = 0;
    
    for(int i=0; i<wordsSize; ++i){
        char *word = words[i];
        int len = strlen(word);
        int rowNum = -1;
        
        for(int j=0; j<len; ++j){
            char c = word[j];
            if(j==0){
                if(contains(keyboard[0], c)) 
                    rowNum = 0;
                else if(contains(keyboard[1], c)) 
                    rowNum = 1;
                else 
                    rowNum = 2;
            }else if(!contains(keyboard[rowNum], c)) break;
            
            if(j == len-1) validWords[idx++] = word;
        }
    }
    
    *returnSize = idx;
    return validWords;
}


int main(){
    return 0;
}

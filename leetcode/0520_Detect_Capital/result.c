/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-30 21:25:21
 *   Description   ：
 */
int capital(char c){
    if(c>=65 && c<=90){
        return 1;
    }
    else{
        return 0;
    }
}
bool detectCapitalUse(char* word){
    int len = strlen(word);
    int i;
    int flag=0;
	
	// if first letter is not capital
    if(!capital(*word)){
        for(i=1;i<len;i++){
		    // if any other letter is capital then break and return false else return true
            if(capital(*(word+i))){
                flag=1;
                break;
            }
        }
        if(flag==1){
            return false;
        }
	
        else{
            return true;
        }
    }
   	// if first letter is capital
    else{
        int count=0;
        for(i=1;i<len;i++){
		    // count capital letters
            if(capital(*(word+i))){
                count++;
            }
        }
		// ignoring the first letter and checking if other letters are capital or not. If count is not zero or len-1 then we know that there is mixture of capital and small letters.
        len = len-1;
        if(count = len || count == 0){
            return true;
        }
        else{
            return false;
        }
    }
}=


/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-19 18:47:28
 *   Description   ：
 */
char * reverseVowels(char * s){
int head, tail;
char swap;
char* vowels="aeiouAEIOU";
if (strlen(s)<2) return s;
head=0;
tail=strlen(s)-1;
while (head<tail) 
    if (!strchr(vowels,s[head])) head++;
      else if (!strchr(vowels,s[tail])) tail--;
             else {
                 swap=s[head];
                 s[head++]=s[tail];
                 s[tail--]=swap;
             }
return s;
}

int main(){
    return 0;
}

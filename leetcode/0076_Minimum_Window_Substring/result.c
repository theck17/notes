/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-27 13:15:31
 *   Description   ：
 */
char * minWindow(char * s, char * t){
    if(!s || !t)
        return NULL;
    int toFind[256]={0};
    int hasFound[256]={0};
    int winCount=strlen(t),i,j=0,start=0,end=0;
    int len=strlen(s),count=0,max=-1;
    if(len < winCount)
    {
        return "";
    }
    for(i=0;i<winCount;i++)
    {
        toFind[t[i]]++;
    }
    for(i=0;i<len;i++)
    {
        if(toFind[s[i]])
        {
            hasFound[s[i]]++;
            if(hasFound[s[i]] <= toFind[s[i]])
            {
                count++;
                if(count == winCount && max==-1)
                {
                    start = j;
                    end = i;
                    max = i-j+1;
                }
            }
            if(count == winCount)
            {
                while(!hasFound[s[j]] || hasFound[s[j]]>toFind[s[j]])
                {
                   
                    
                    if(hasFound[s[j]]>toFind[s[j]])
                    {
                        hasFound[s[j]]--;
                   }
                    j++;
                    if((i-j+1) < max)
                    {
                        start =j;
                        end = i;
                        max=i-j+1;
                    }
                     
                    
                }
            }
        }
    }
    if(count != winCount)
    {
        return "";
    }
    char* str = malloc(sizeof(char) * (end - start + 2));
    j=0;
    for(i =start;i <= end;i++)
    {
        str[j]=s[i];
        j++;
    }
    str[j]='\0';
    return str;
} 

int main(){
    return 0;
}

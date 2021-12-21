/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-21 22:37:37
 *   Description   ：
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int temp=2000;
    int temp1=0;
    char** result=(char**)malloc(sizeof(char*)*list1Size);
    for(int i=0;i<list1Size;i++)
    {
        if(i>temp)
        {break;}
        for(int j=0;j<list2Size;j++)
        {
            if(i+j>temp)
            {break;}
            if(strcmp(list1[i],list2[j])==0)
            {
                if(temp==i+j)
                {
                    result[temp1]=(char*)malloc(sizeof(char)*(strlen(list1[i])+1));      
                    strcpy(result[temp1],list1[i]);
                    temp1++;
                    temp=i+j;
                }
                if(temp>i+j)
                {
                    temp1=0;
                    result[temp1]=(char*)malloc(sizeof(char)*(strlen(list1[i])+1));      
                    strcpy(result[temp1],list1[i]);
                    temp1++;
                   temp=i+j;
                }
            }         
        }
    }
    *returnSize=temp1;
    return result;
} 

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-05 10:11:44
 *   Description   ：
 */
char* multiply(char* num1, char* num2)
{
    if(*num1=='0' || *num2=='0') return "0";
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1+len2;
    int *arr = (int*)malloc(sizeof(int)*len); //the number of digits of the result - len is the top;
    memset(arr, 0, sizeof(int)*len); //this is critical;
    for(int i=len1-1; i > -1; i--)
        for(int j=len2-1; j > -1; j--)
            arr[i+j+1] += (num1[i]-'0')*(num2[j]-'0'); //collect result of each position;
    for(int i=len-1; i > 0; i--) //restore the carry for each position and get the final result;
    {
        arr[i-1] += arr[i]/10;
        arr[i] %= 10;
    }
    char *s = (char*)malloc(sizeof(char)*(len+1)); //converting the digits result to string;
    int index = 0;
    int i = 0;
    if(arr[i]==0) i++; //in case the zero position has no carry, if it does, ignore it;
    while(i < len)
        s[index++] = arr[i++]+'0';
    s[index] = '\0';
    return s;
}

int main(){
    return 0;
}

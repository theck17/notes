/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-17 19:05:49
 *   Description   ：
 */
int count_ones(int n)
{
    int count=0;
    while(n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

char** readBinaryWatch(int num, int* returnSize)
{
    char **ans = malloc(sizeof(char *) * 1024);
    int ret_count=0;
        
    for(int h=0;h<12;h++)
    {
        for(int m=0;m<60;m++)
        {
            int tmp = (h<<6)|m;
            if(count_ones(tmp)==num)
            {                
                char *tmp = malloc(sizeof(char)*6);
                sprintf(tmp,"%d:%02d",h%12,m%60);
                ans[ret_count++] = tmp;
            }
        }
    }
    *returnSize=ret_count;
    return ans;
}

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-01 14:21:14
 *   Description   ：
 */
bool checkPerfectNumber(int num)
{
    if(num==1)
        return false;
    
    int divisor = 2;
    int sum = 1;
    while( (divisor*divisor)<num)
    {
        if((num%divisor) == 0)
        {
            sum += divisor + num/divisor;
        }
        divisor++;
    }
    return (sum==num);
}}

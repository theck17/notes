/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-22 20:27:22
 *   Description   ：
 */
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    if(timeSeriesSize==0)
        return 0;
    int count=0;
    for(int i=1;i<timeSeriesSize;i++)
    {
        if(timeSeries[i]-timeSeries[i-1]>=duration)
            count+=duration;
        else 
            count+=timeSeries[i]-timeSeries[i-1];
    }
    return count+duration;
}

int main(){
    return 0;
}

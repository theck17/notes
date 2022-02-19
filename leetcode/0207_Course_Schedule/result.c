/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-19 10:54:27
 *   Description   ：
 */
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int takenCourse=0;
    int i=0,j=0,k=0,m=0;
    int exist=0;
    int count=0;
    int temp=0;
    int loop=0;
    int position_num=0;
    if(numCourses<0||prerequisitesSize<0||prerequisitesColSize<0) return 0;
    if(numCourses==0) return 0;
    if(numCourses>=1&&prerequisitesSize==0&&prerequisitesColSize==0) return 1;
    int *num=calloc(numCourses,sizeof(int));
    int *position=calloc(prerequisitesSize,sizeof(int));
    for(i=0;i<prerequisitesSize;i++){
        count=0;
        num[count]=prerequisites[i][0];
        count++;
        num[count]=prerequisites[i][1];
        position_num=0;
        position[position_num]=i;
        position_num++;
        for(j=0;j<prerequisitesSize;j++){
           if(prerequisites[j][0]==num[count]){
                    for(k=0;k<=count;k++){
                        if(num[k]==prerequisites[j][1]){
                            return 0;
                       }
                    }
                     count++;
                     num[count]=prerequisites[j][1];
                     position[position_num]=j;
                     position_num++;
                     j=0;
                     if(position_num==prerequisitesSize) return 1;
            }
        }
        
}
    return 1;
} 

int main(){
    return 0;
}

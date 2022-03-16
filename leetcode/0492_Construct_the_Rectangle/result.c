/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-22 09:56:33
 *   Description   ：
 */
int* constructRectangle(int area, int* returnSize){
    int* ReturnArray=calloc(2,sizeof(int));
    * returnSize=2;
    int i=sqrt(area);
    while(i){
    	if(!(area%i)){
    		*ReturnArray=area/i;
    		*(ReturnArray+1)=i;
    		break;
    	}
    	i--;
    }
    return ReturnArray;
}


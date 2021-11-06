/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-06 14:08:44
 *   Description   ：
 */
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int *c = malloc(sizeof(int)*gasSize);
    int i, j, sum = 0, n;
    
    for (i = 0; i < gasSize; i++)
        c[i] = gas[i] - cost[i];
    
    for (j = 0; j < gasSize;) {
        for (i = j, n = 0; n < gasSize; i++, n++) {
            sum += c[i % gasSize];
            if (sum < 0) {
                j = i+1;
                break;
            }
        }
        if (sum >= 0)
            break;
        sum = 0;
    }
    
    free(c);
    
    if(j >= gasSize)
        j = -1;
    
    return j;
}

int main(){
    return 0;
}

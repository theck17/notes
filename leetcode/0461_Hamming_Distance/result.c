/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-31 10:52:43
 *   Description   ：
 */
int hammingDistance(int x, int y) {
    int distance = 0;
    while(x!=y){
        distance += (x%2) ^ (y%2);
        x>>=1;
        y>>=1;
    }
    
    return distance;
}

int main(){
    return 0;
}

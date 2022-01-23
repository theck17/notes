/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-23 10:47:15
 *   Description   ：
 */
int guessNumber(int n){
    long long left = 1, right = n;
	while(left < right){
        long long mid = (left + right) / 2;
        int type = guess(mid);
        if(type == 0) return mid;
        else if(type == -1) right = mid - 1;
        else if(type == 1) left = mid + 1;
    }
    return left;
}

int main(){
    return 0;
}

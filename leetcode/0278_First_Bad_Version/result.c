/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-08 09:04:34
 *   Description   ：
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
int firstBadVersion(int n) {
    long left = 1, right = n;
    while(left <= right)
    {
        long mid = (left + right)/2;
        if(isBadVersion(mid))
            right = mid - 1;
        else left = mid + 1;
    }
    return (int)left;
}

int main(){
    return 0;
}

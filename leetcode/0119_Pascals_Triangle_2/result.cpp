/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-27 20:15:34
 *   Description   ：
 */
#include <ctime>           //定义关于时间的函数
using namespace std;


class Solution {
    long long computeProduct(int a, int b, int c) {
        long long product=1;
        int index=2;
        for(int i=a;i>b;i--) {
            product*=i;
            if(index<=c&&product%index==0) {
                product/=index;
                index++;
            }
        }
        
        while(index<=c) {
            product/=index;
            index++;
        }
        return product;
    }
    int compute(int n, int r) {
        return computeProduct(n,r,n-r);
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int i=0;i<=rowIndex;i++) {
            result.push_back(compute(rowIndex, i));
        }
        return result;
    }
};



int main(){
    return 0;
}

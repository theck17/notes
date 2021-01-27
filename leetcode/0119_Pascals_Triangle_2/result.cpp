/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-27 20:15:34
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <memory>          //STL通过分配器进行的内存分配
#include <new>             //动态内存分配
#include <numeric>         //STL常用的数字操作
#include <iostream>        //数据流输入／输出
#include <istream>         //基本输入流
#include <iterator>        //STL迭代器
#include <ostream>         //基本输出流
#include <queue>           //STL 队列容器
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

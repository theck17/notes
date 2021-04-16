/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-16 18:18:35
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    int getPermute(long long m, long long n) {
        // calculate (m + n)! / (m! * n!)
        if (m == 0 || n == 0) return 1;

        if (m < n) {
            m = m + n;
            n = m - n;
            m -= n;
        }

        long long result = 1;
        for (int i = 1 ; i <= n ; i++) {
            result = (result * (m + n - i + 1)) / i;
        }
        return (int)result;
    }
    
    int uniquePaths(int m, int n) {
        return getPermute(m - 1, n - 1);
    }
};




int main(){
    return 0;
}

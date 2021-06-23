/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-06-23 19:22:14
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
    int countPrimes(int n) {
        if (n == 0)
            return 0;
        bool prime [n];
        memset (prime, true, sizeof (prime));
        for (int i = 2; i*i < n; i++) {
            if (prime [i] == true) { 
				// Update all multiples of i to false if i is prime
                for (int j = i * i; j < n; j += i)
                    prime [j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime [i])
                count++;
        }
        return count;
    }
};

int main(){
    return 0;
}

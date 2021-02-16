/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-10 20:47:38
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <cctype>          //字符处理
#include <vector>          //STL 动态数组容器
#include <ctime>           //定义关于时间的函数
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target)
                r--;
            else if (sum < target)
                l++;
            else
                return { l + 1, r + 1 };
        }
        return {}; 
    }
};



int main(){
    return 0;
}

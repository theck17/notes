/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：resutl.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-07 09:59:30
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <cctype>          //字符处理
#include <cerrno>          //定义错误码 
#include <cfloat>          //浮点数处理 
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int sz = nums.size();
        vector<int> sol;
        for (int i = 0; i < sz; i++) {
            int v = abs(nums[i]) % sz;
            if (nums[v] > sz) {
                sol.push_back(v == 0 ? sz : v);
                nums[v] = -nums[v];
            } else if (nums[v] >= 0){
                nums[v] += sz;
            }
        }
        return sol;
    }
};



int main(){
    return 0;
}

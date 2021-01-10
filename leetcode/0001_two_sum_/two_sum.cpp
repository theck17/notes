/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：two_sum.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-11 00:26:27
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <bitset>           //STL 位集容器
#include <cctype>          //字符处理
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size_of_arr = sizeof nums; 
        for (int a=0; a<=size_of_arr;a++){
            for (int b=a+1; b<=size_of_arr;b++){
                int temp = nums[a] + nums[b];
                if (temp == target){
                    return {a ,b};
                }
            }
        }
        return {};
    }
};



int main(){
  std::vector<int> my_arr[4] = [2,7,11,15]
  int my_sum = 9
  Solution mySolution;          // 创建一个对象
  mySolution.twoSum(&my_arr, &`my_sum);  // 调用该对象的成员函数
  return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-10 19:50:49
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <bitset>           //STL 位集容器
#include <cctype>          //字符处理
#include <cerrno>          //定义错误码 
#include <cfloat>          //浮点数处理 
#include <ciso646>         //对应各种运算符的宏
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }else{
                ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count);
        return ans;
    }
};




int main(){
    return 0;
}

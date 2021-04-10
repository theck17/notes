/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-10 20:34:28
 *   Description   ：
 */
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int missing=1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>missing){
                return missing;
            }else if(nums[i]==missing){
                missing++;
            }
        }
        
        return missing;
    }
};




int main(){
    return 0;
}

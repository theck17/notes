/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-17 19:31:28
 *   Description   ：
 */
#include <stack>           //STL 堆栈容器
#include <stdexcept>       //标准异常类
#include <streambuf>       //底层输入／输出支持
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        int resDiff = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = 0;
        
        for(int k = 0; k < nums.size() - 1; k++)
        {
            i = k + 1;
            j = nums.size() - 1;
            
            while(i < j)
            {
                int val = nums[i] + nums[j] + nums[k];
                int valSub = target - val;
                
                if(valSub == 0)
                    return val;
                else if(valSub < 0)
                    j--;
                else
                    i++;
                valSub = abs(valSub);
                if(resDiff > valSub)
                {
                    resDiff = valSub;
                    res = val;
                }
            }
            
            
        }
        
        return res;
        
    }
};



int main(){
    return 0;
}

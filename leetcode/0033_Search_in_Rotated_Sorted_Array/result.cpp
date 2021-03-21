/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-21 17:59:06
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
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l=0,r=n-1;
       
        while(l<=r){
            int mid = (l+r)/2;
            int midd=nums[mid], left=nums[l], right = nums[r];   
            if(target==midd) return mid;
            
            if(left>midd){
                if(target>midd && target<=right) l=mid+1;
                else r=mid-1;
            }else if(midd>right){
                if(target<midd && target>=left) r=mid-1;
                else l=mid+1;
            }else{
                if(target>midd)  l=mid+1;
                else r=mid-1;
            }
            
        }
        return -1;
    }
};




int main(){
    return 0;
}

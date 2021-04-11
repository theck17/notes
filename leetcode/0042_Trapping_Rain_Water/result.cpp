/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-11 10:39:43
 *   Description   ：
 */
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;



class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans=0;
        if(n==0 || n==1) return 0;
        int l=0,r=n-1,lmax=0,rmax=0;
        while(l<r){
          if(height[l]<=height[r]){  //in this we are confirmed that in right there is atleast one which is bigger or equal to lmax
                if(height[l]>lmax)   //lmax is updated
                    lmax=height[l];
                else
                    ans+=(lmax-height[l]);  //we only see for lmax as we know at right rmax is surely greater than equal to lmax
                l++;
            }
            else{                   //same cases applied in vice versa manner here
                if(height[r]>rmax)
                    rmax=height[r];
                else
                    ans+=(rmax-height[r]);
                r--;
            }
        }
        return ans;
    }
};


int main(){
    return 0;
}

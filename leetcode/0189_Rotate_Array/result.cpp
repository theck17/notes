/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-06-07 18:41:38
 *   Description   ：
 */
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz,n;
        sz=n=nums.size();
        k%=n;
        if(n<2 || k<1) return;
        for(int i=k;n>0;++i) {
            int j=i, prev=nums[(i-k)%k];
			while(n-->0) {
				std::swap(prev,nums[j]);
                j=(j+k)%sz;
				if(j==i) break;
			}
        }
    }
};
int main(){
    return 0;
}

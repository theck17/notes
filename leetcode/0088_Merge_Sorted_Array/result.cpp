/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-24 13:51:22
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <queue>           //STL 队列容器
#include <set>             //STL 集合容器
#include <sstream>         //基于字符串的流
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i=m-1,j=n-1,k=m+n-1;
	while(i>=0&&j>=0)
	{
		if(nums1[i]>nums2[j])
		{
			nums1[k]=nums1[i];
			i--;
		}
		else
		{
			nums1[k]=nums2[j];
			j--;
		}
		k--;
	}
	while(j>=0)
	{
		nums1[k]=nums2[j];
		j--;
		k--;
	}
}
};



int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-19 21:43:59
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <istream>         //基本输入流
#include <iterator>        //STL迭代器
#include <ostream>         //基本输出流
#include <set>             //STL 集合容器
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;


class Solution {
public:
    int minWall(std::vector<int>& height, int l, int r){
		return height[l]<height[r]? height[l]: height[r];
	}
	int square(std::vector<int>& height, int l, int r){
		return (r-l) * minWall(height, l, r);
	}
    int maxArea(std::vector<int>& height) {
       int left = 0;
	   int right = height.size() - 1;
	   int maxSquare = square(height, left, right);
	   int min = minWall(height, left, right);
	   while (left < right){
			while (min >= height[left] && left < right) left++;
			while (min >= height[right] && left < right) right--;
			min = minWall(height, left, right);

			int curSquare = square(height, left, right);
			if (curSquare > maxSquare){
				maxSquare = curSquare;
			}
	   }
	   return maxSquare;
    }
};



int main(){
    return 0;
}

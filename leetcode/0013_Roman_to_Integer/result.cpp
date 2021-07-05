/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-07-05 19:09:09
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
        int romanToInt(string s) {
            int num = 0;
            int size = s.size();
            
            for (int i = 0; i < size; i++) {
            	if (i < (size - 1) && romanCharToInt(s[i]) < romanCharToInt(s[i + 1])) {
            		num -= romanCharToInt(s[i]);
            	} else {
    				num += romanCharToInt(s[i]);
    			}
            }
            return num;
        }
        
        int romanCharToInt(char c) {
        	switch (c) {
        		case 'I': 	return 1;
        		case 'V':	return 5;
        		case 'X':	return 10;
        		case 'L':	return 50;
        		case 'C':	return 100;
        		case 'D':	return 500;
        		case 'M':	return 1000;
        		default:	return 0;
        	}
        }
    };

int main(){
    return 0;
}

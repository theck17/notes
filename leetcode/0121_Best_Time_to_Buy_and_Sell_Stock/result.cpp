/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-03 19:11:18
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法

#include <istream>         //基本输入流
#include <iterator>        //STL迭代器
#include <ostream>         //基本输出流
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
    int maxProfit(vector<int>& prices) {
		//init ans,min_num,max_num
        int ans = 0;
        int min_num = INT_MAX;
        int max_num = INT_MIN;
		//read all num
        for(int i=0;i<prices.size();i++){
			//update min and max;
            min_num = min(prices[i],min_num);
            max_num = max(prices[i],max_num);
			//if min_num just update init the max_num,
			//cause max shoud appear after min
            if(min_num==prices[i]){
                max_num = INT_MIN;
			//else update ans
            }else{ans = max(ans,max_num-min_num);}
        }
        return ans;
    }
};




int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-07 22:21:24
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
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
        int max = 0;
        int min = prices[0];
        int firstmax = 0;
        vector<int> arr(prices.size(),0);
        for (int i = 0; i < prices.size(); i++){
           max = (max > (prices[i]-min))? max: prices[i]-min;
            min = (min < prices[i])? min: prices[i];
            arr[i] = max;
            firstmax = firstmax > max? firstmax: max;
        }
        max = prices[prices.size()-1];
        int maxsum = 0;
        for (int i = prices.size()-1; i >= 0; i--){
            if (i == 0){
                maxsum = maxsum > arr[0]? maxsum: arr[0];
            }
            else {
    maxsum = (maxsum > (max-prices[i]+arr[i-1])? maxsum: (max-prices[i]+arr[i-1]));
            max = max > prices[i]? max: prices[i];
        }
        }
        return maxsum > firstmax? maxsum: firstmax;
    }
};



int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-07-09 19:42:43
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
    bool isValid(string s) {
        stack<char> stk;
        for(const auto& c : s){
            switch(c){
                case '{':  stk.push('}'); break;
                case '[':  stk.push(']'); break;
                case '(':  stk.push(')'); break;
                default:
                    if(stk.size() == 0 || c != stk.top()) return false;
                    else stk.pop();
            }
        }
        return stk.size() == 0;
    }
};

int main(){
    return 0;
}

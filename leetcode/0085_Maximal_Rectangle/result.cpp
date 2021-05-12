/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-05-12 19:34:26
 *   Description   ：
 */
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()|| matrix[0].empty())
            return 0;
        int rows=matrix.size(),cols=matrix[0].size(),ret=0;
        vector<int> h(cols+1);
        for(int i=0;i<rows;i++) {
            stack<int> lowi;
            for(int j=0;j<=cols;j++) {
                h[j]=((j!=cols && matrix[i][j]=='1')?h[j]+1:0);
                while(!lowi.empty() && (h[j]<h[lowi.top()])){
                    int height=h[lowi.top()];
                    lowi.pop();
                    int lefti=(lowi.empty()?-1:lowi.top());
                    ret=max((j-lefti-1)*height,ret);
                }
                lowi.push(j);
            }
        }
        return ret;     
    }
};




int main(){
    return 0;
}

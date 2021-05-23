/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-05-22 19:09:14
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        vector<int> mini = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        return mini[0];
    }
};




int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-23 19:03:01
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
using namespace std;

class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        while(i<matrix.size()&&j>=0)
        {
            if(target<matrix[i][j])
                j--;
            else if(target>matrix[i][j])
                i++;
            else
                return true;
        }
        return false;
    }
};




int main(){
    return 0;
}

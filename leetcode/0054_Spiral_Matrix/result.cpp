/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-03 11:20:53
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <vector>          //STL 动态数组容器
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        int row_start = 0, row_end = M - 1;
        int col_start = 0, col_end = N - 1;
        
        vector<int> order;
        while(row_start <= row_end && col_start <= col_end) {
            // top row
            for(int i = col_start; i <= col_end && row_start <= row_end; i++)
                order.emplace_back(matrix[row_start][i]);
            ++row_start;
            
            // left col
            for(int i = row_start; i <= row_end && col_start <= col_end; i++)
                order.emplace_back(matrix[i][col_end]);
            --col_end;
            
            // bottom row
            for(int i = col_end; i >= col_start && row_start <= row_end; i--)
                order.emplace_back(matrix[row_end][i]);
            --row_end;
            
            // right col
            for(int i = row_end; i >= row_start && col_start <= col_end; i-)
                order.emplace_back(matrix[i][col_start]);
            ++col_start;
        }
        return order;
    }
};-




int main(){
    return 0;
}

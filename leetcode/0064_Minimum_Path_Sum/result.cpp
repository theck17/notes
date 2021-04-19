/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-19 18:27:40
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
    int minsum= INT_MAX;
    int dp[201][201];
    int minPathSum(vector<vector<int>>& grid) 
        {
            // Minimum or maxu/imum problem
            // Greedy algorithm
            // Dynamic programming
            memset(dp,-1,sizeof(dp)) ;
            return  helper(grid, 0,0 )    ;
        }

    int helper(vector<vector<int>>& grid , int i, int j )
        {
            if(dp[i][j]!=-1) return dp[i][j];
            if( i ==grid.size()-1 && j == grid[0].size()-1) return dp[i][j] = grid[i][j];

            if(i>=grid.size() || j >= grid[0].size()) return INT_MAX ;

            int v1 =  helper(grid, i+1 ,j  );
            int v2 =  helper(grid, i   ,j+1  );

            return  dp[i][j] = min(v1,v2) + grid[i][j] ;

        }
 };




int main(){
    return 0;
}

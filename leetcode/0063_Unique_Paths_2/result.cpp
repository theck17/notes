/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-17 08:07:54
 *   Description   ：
 */
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    typedef int int64_t;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        unsigned int dp[m][n];
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                
                else if(i == m-1 && j == n-1)
                    dp[i][j] = 1;
                
                else if(i == m-1){
                    if(dp[i][j+1] == 0)
                        dp[i][j] = 0;
                    
                    else
                        dp[i][j] = 1;
                }
                
                else if(j == n-1){
                    if(dp[i+1][j] == 0)
                        dp[i][j] = 0;
                    
                    else
                        p[i][j] = 1;
                }
                    
                else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }       
            }
        }
        
        return dp[0][0];
        
    }
};d




int main(){
    return 0;
}

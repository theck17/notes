/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-04-14 18:46:17
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <vector>          //STL 动态数组容器
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //int **arr=(int**)malloc(sizeof(int*)*n); //c allows implict void* -> t* conversion, c++ disallows
        //for (int i=0; i<n;++i ) arr[i]=(int*)calloc(n,sizeof(int)); 
        vector<vector<int>> result(n,vector<int>(n,0));
        int next[][2] ={{0,1},{1,0},{0,-1},{-1,0}};
        int r=0,c=0,d=0;
        for (int i=1; i<=n*n; ++i) {
            result[r][c]=i;
            int nr=r+next[d][0], nc=c+next[d][1];
            if (nr>=n || nc>=n ||nr<0 ||nc<0|| result[nr][nc] ) {
                d=(d+1)%4;
                nr=r+next[d][0],nc=c+next[d][1];
            }
            r=nr,c=nc;
        }
        return result;
    }
};




int main(){
    return 0;
}

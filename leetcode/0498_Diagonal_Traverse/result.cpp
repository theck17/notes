/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-19 12:29:40
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        vector<int> res;
        for(int s = 0; s <= N + M - 2; ++s)
        {
            // for all i + j = s
            for(int x = 0; x <= s; ++x) 
            {
                int i = x;
                int j = s - i;
                if(s % 2 == 0) swap(i, j);

                if(i >= N || j >= M) continue;
                
                res.push_back(matrix[i][j]);
            }
        }
        
        return res;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-31 20:39:24
 *   Description   ：
 */
#include <vector>          //STL 动态数组容器
using namespace std;

class Solution {
public:
   void rotate(vector<vector<int>>& matrix) {
	vector<vector<int>> mat = matrix;
	int n = mat.size();
	for (int i = 0, j1 = 0; i < n, j1 < n; i++, j1++)
		for (int j = 0, i1 = n - 1; j < n, i1 >= 0; j++, i1--)
			matrix[i][j] = mat[i1][j1];
    }
};




int main(){
    return 0;
}

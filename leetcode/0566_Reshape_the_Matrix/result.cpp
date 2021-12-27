/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-27 21:48:02
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size(), o = m * n;
        if (r * c != o) return nums;
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < o; i++) res[i / c][i % c] = nums[i / n][i % n];
        return res;
    }
};

int main(){
    return 0;
}

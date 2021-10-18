/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-18 18:36:07
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int f[2][4], i, j;
        f[0][0] = f[1][0] = 1;
        for (j = 3; j > 0; --j) {
            f[0][j] = INT_MIN;
            f[1][j] = INT_MAX;
        }        
        
        for (i = 0; i < nums.size(); ++i) {
            for (j = 3; j > 0; --j) {
                if (f[0][j - 1] == INT_MIN) {
                    continue;
                }
                f[0][j] = max(f[0][j], max(f[0][j - 1] * nums[i], f[1][j - 1] * nums[i]));
                f[1][j] = min(f[1][j], min(f[0][j - 1] * nums[i], f[1][j - 1] * nums[i]));
            }
        }                              
        return f[0][3];
    }
};

int main(){
    return 0;
}

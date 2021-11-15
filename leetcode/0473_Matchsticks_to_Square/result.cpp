/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-15 20:06:30
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();

        long sum = accumulate(nums.begin(), nums.end(), 0l);
        if (sum % 4)
            return false;
        long sideLen = sum / 4;
        vector<int> usedMasks;
        vector<bool> validHalfSubsets(1<<n, false);

        int all = (1 << n) - 1;
        for (int mask = 0; mask <= all; mask++) {
            long subsetSum = 0;
            for (int i = 0; i < 32; i++) {
            if ((mask >> i) & 1)
            subsetSum += nums[i];
            }
        if (subsetSum == sideLen) {
            for (int usedMask : usedMasks) {
                if ((usedMask & mask) == 0) {
                int validHalf = usedMask | mask;
                validHalfSubsets[validHalf] = true;
                if (validHalfSubsets[all ^ validHalf])
                    return true;
                }
                }
            usedMasks.push_back(mask);
            }
        }
        return false;
    }
};

int main(){
    return 0;
}

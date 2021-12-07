/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-07 21:41:19
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && nums[i] == sorted[i]) {
            i++;
        }
        while (j > i && nums[j] == sorted[j]) {
            j--;
        }
        return j + 1 - i;
    }
};

int main(){
    return 0;
}

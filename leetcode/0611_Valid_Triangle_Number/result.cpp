/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-18 21:21:52
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = n-1; i >= 0; i--) {
            int lo = 0, hi = i-1;
            
            while (lo < hi) {
                if (nums[lo] + nums[hi] > nums[i]) {
                    res += hi - lo;
                    hi--;
                }
                
                else lo++;
            }
        }
        
        return res;
    }
};

int main(){
    return 0;
}

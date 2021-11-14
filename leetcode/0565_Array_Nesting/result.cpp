/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-14 15:00:26
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0, curr, count, prev;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) continue;
            
            curr = nums[i], count = 1, nums[i] = -1;
            
            while (nums[curr] != -1) {
                prev = curr;
                curr = nums[curr];
                nums[prev] = -1;
                count++;
            }
            
            res = max(res, count);
        }
        
        return res;
    }
};

int main(){
    return 0;
}

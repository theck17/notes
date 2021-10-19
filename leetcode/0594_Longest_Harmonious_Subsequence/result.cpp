/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-19 20:48:11
 *   Description   ：
 */
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = 0;
        for(int i = 1, start = 0, new_start = 0; i<nums.size(); i++)
        {

            if (nums[i] - nums[start] > 1)    
                start = new_start;
            if (nums[i] != nums[i-1]) 
                new_start = i;
            if(nums[i] - nums[start] == 1)
                len = max(len, i-start+1);
        }
        return len;
    }
};

int main(){
    return 0;
}

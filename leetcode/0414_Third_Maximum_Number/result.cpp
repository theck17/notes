/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-03 19:48:08
 *   Description   ：
 */
using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        if (nums.size()<3)
        {
            return *max_element(nums.begin(),nums.end());
        }
        else
        {
            set<int>s(nums.begin(),nums.end());
            vector<int>ans(s.begin(),s.end());
            if (ans.size()<3)
            {
                return *max_element(ans.begin() , ans.end());
            }
            else
            {
                return ans[ans.size()-3];
            }
        }
    }
};



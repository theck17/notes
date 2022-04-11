/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-20 18:11:55
 *   Description   ：
 */
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
    
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
        }
        index++;
        int j=n-1;
        
        while(index<j){
            swap(nums[index],nums[j]);
            j--;index++;
        }
       
        return;
    }
};




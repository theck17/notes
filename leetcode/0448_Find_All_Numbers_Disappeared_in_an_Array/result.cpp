/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-08 19:44:42
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <vector>          //STL 动态数组容器
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> solution;
        for (int i = 0; i < nums.size(); i++) {
            // set "temp" to the positive version of the int at nums[i]
            int temp = (nums[i]>0) ? nums[i] : -nums[i];
            // denote having "seen" nums[i] by making the nums[i] number in the array negative
            // for example, if nums[i] is 4, we set nums[3] (which is the fourth number) to be negative
            nums[temp-1] = (nums[temp-1]>0) ? -nums[temp-1] : nums[temp-1];
        }
        for (int j = 0; j < nums.size(); j++) {
		    // if number is positive, hasn't been seen
            if (nums[j] > 0) {
			    // indices start at 0, our numbers start at 1, so add 1
                solution.push_back(j+1);
            }
        }
        return solution;
    }
};



int main(){
    return 0;
}

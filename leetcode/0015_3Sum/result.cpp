/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-15 00:03:12
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.empty()) {
		return result;
	}

	int n= nums.size();
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++) {
		if (nums[i] > 0) {
            break;
        }
		if (i > 0 and nums[i] == nums[i-1]){
            continue;
        }
		int left = i+1, right = n - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum < 0) {
				left++;
			} else if (sum > 0) {
				right--;
			} else {
				result.push_back({nums[i], nums[left], nums[right]});
				int last_left = nums[left], last_right = nums[right];
				while (left < right && nums[left] == last_left) left++;
				while (left < right && nums[right] == last_right) right--;
			}
		}

	}
	return result;
}
};




int main(){
    return 0;
}

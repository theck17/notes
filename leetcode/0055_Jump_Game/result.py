# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-05 10:12:37
# Description:


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        min_num_index = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] + i >= min_num_index:
                min_num_index = i
        return nums[0] >= min_num_index


if __name__ == "__main__":
    pass

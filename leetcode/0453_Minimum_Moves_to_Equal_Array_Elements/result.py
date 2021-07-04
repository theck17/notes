# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-07-02 20:04:41
# Description:

import os


class Solution:
    def minMoves(self, nums: List[int]) -> int:
        nums.sort()
        c = 0
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] == nums[0]:
                break
            c += nums[i] - nums[0]
        return c

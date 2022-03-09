# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-07 21:42:13
# Description:
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        right_ptr = 0
        big = nums[0]
        for i in range(len(nums)):
            if nums[i] < big:
                right_ptr = i
            else:
                big = nums[i]

        left_ptr = 0
        small = nums[-1]
        for i in reversed(range(len(nums))):
            if nums[i] > small:
                left_ptr = i
            else:
                small = nums[i]

        if right_ptr == left_ptr: return 0
        return right_ptr - left_ptr + 1

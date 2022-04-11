# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-20 18:14:01
# Description:


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums) - 1, 0, -1):
            if nums[i] > nums[i - 1]:
                # find the mininum item that's greater than nums[i-1]
                min_v = inf
                k = 0
                for j in range(i, len(nums)):
                    if nums[j] > nums[i - 1] and nums[j] < min_v:
                        k = j
                        min_v = nums[j]

                # exchange
                nums[i - 1], nums[k] = nums[k], nums[i - 1]

                # sort
                nums[i:] = sorted(nums[i:])
                return

        # otherwise
        nums.sort()

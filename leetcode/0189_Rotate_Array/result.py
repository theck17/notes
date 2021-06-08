# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-06-07 18:40:42
# Description:

import os


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        if len(nums) > 1 and k > 0:
            nums[:] = nums[-k:] + nums[:-k]


if __name__ == "__main__":
    pass

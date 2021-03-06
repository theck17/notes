# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-03 19:47:00
# Description:

import os, sys


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = set(nums)
        if len(nums) <= 2:
            return max(nums)
        elif len(nums) > 2:
            counter = 0
            while counter < 2:
                nums.remove(max(nums))
                counter += 1
            return max(nums)


if __name__ == "__main__":
    pass

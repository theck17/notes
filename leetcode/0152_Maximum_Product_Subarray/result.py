# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-05-29 13:43:51
# Description:

import os
import sys


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        B = nums[::-1]
        for i in range(1, len(nums)):
            nums[i] *= nums[i - 1] or 1
            B[i] *= B[i - 1] or 1
        return max(nums + B)


if __name__ == "__main__":
    pass

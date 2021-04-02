# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-29 20:12:20
# Description:

import os
import sys


class Solution:
    def jump(self, nums):
        dp = [0] * len(nums)
        for i in range(len(nums) - 2, -1, -1):
            dp[i] = dp[i + 1] + 1
            nextPos = i + nums[i]
            if nextPos < len(nums):
                minDP = dp[nextPos]
                for j in range(nextPos - 1, i, -1):
                    if dp[j] < minDP:
                        minDP = dp[j]
                dp[i] = minDP + 1
            else:
                dp[i] = 1
        return dp[0]


if __name__ == "__main__":
    pass

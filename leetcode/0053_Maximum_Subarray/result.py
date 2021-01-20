# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-20 20:16:51
# Description:


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best = nums[0]
        current = nums[0]
        for i in nums[1:]:
            current = max(i, current + i)
            if current > best:
                best = current
        return best


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-06-01 21:39:55
# Description:


class Solution:
    def findMin(self, nums: List[int]) -> int:
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                return nums[i + 1]
        return nums[0]


if __name__ == "__main__":
    pass

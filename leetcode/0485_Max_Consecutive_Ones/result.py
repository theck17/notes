# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-10 19:46:25
# Description:

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:

        for i in range(1, len(nums)):
            if nums[i - 1] != 0 and nums[i] != 0:
                nums[i] += nums[i - 1]
        return max(nums)


if __name__ == "__main__":
    pass

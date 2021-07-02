# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-07-02 20:04:41
# Description:


class Solution:
    def minMoves(self, nums: List[int]) -> int:
        c = 0
        while True:
            max1, min1 = max(nums), min(nums)
            if max1 == min1:
                break
            idx, c = nums.index(max1), c + 1
            for i in range(len(nums)):
                nums[i] = nums[i] + 1 if i != idx else nums[i]
        return c


if __name__ == "__main__":
    pass

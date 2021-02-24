# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-02-24 21:21:24
# Description:
import os, sys


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        for i in range(nums.count(val)):
            valIndex = nums.index(val)
            del nums[valIndex]
        return len(nums)


if __name__ == '__main__':
    pass

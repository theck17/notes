# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-14 15:01:17
# Description:
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        res, l = 0, len(nums)
        globalSet = set()
        for k in range(l):
            if k not in globalSet:
                currLength, currSet, val = 0, set(), k
                while True:
                    if nums[val] in currSet: break
                    currSet.add(nums[val])
                    globalSet.add(nums[val])
                    currLength, val = currLength + 1, nums[val]
                res = max(res, currLength)
        return res


if __name__ == "__main__":
    pass

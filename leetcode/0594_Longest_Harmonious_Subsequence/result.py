# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-19 20:51:42
# Description:
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        count = collections.Counter(nums)
        return max([count[x] + count[x + 1] for x in count if count[x + 1]]
                   or [0])


if __name__ == "__main__":
    pass

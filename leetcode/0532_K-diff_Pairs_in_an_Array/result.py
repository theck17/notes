# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-12 22:37:18
# Description:
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        res = 0
        c = collections.Counter(nums)
        for i in c:
            if k > 0 and i + k in c or k == 0 and c[i] > 1:
                res += 1
        return res


if __name__ == "__main__":
    pass

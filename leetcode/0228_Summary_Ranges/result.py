# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-06-21 19:06:23
# Description:


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ranges, r = [], []
        for n in nums:
            if n - 1 not in r:
                r = []
                ranges += r,
            r[1:] = n,
        return ['->'.join(map(str, r)) for r in ranges]


if __name__ == "__main__":
    pass

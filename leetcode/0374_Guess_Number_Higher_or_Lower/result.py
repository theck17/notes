# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-23 10:50:04
# Description:
class Solution:
    def guessNumber(self, n: int) -> int:
        beg, end = 1, n
        while beg <= end:
            mid = (beg + end) // 2
            t = guess(mid)
            if t == 0: return mid
            if t == -1: end = mid - 1
            if t == 1: beg = mid + 1



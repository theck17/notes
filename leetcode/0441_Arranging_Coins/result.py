# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-21 10:37:21
# Description:
class Solution:
    def arrangeCoins(self, n: int) -> int:
        k = total = 1
        while total <= n:
            k += 1
            total += k
        return k - 1

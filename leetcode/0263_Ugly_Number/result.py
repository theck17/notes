# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-28 22:12:00
# Description:
class Solution:
    def isUgly(self, n: int) -> bool:
        if n == 0: return False
        while n % 5 == 0:
            n /= 5
        while n % 3 == 0:
            n /= 3
        while n % 2 == 0:
            n /= 2
        return n == 1

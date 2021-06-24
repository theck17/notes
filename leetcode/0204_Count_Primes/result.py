# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-06-23 19:19:42
# Description:

import os


class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        strikes = [1] * n
        strikes[0] = 0
        strikes[1] = 0
        for i in range(2, int(n ** 0.5) + 1):
            if strikes[i] != 0:
                strikes[i * i:n:i] = [0] * ((n - 1 - i * i) // i + 1)
        return sum(strikes)


if __name__ == "__main__":
    pass

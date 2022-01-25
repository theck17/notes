# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-25 22:22:25
# Description:
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        res = [0 for i in range(n)]
        res[0], res[1] = 1, 2
        for i in range(2, n):
            res[i] = res[i - 1] + res[i - 2]
        return res[-1]


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-31 11:30:13
# Description:
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        Out, t = 0, x ^ y
        while t:
            t, Out = t & (t - 1), Out + 1
        return Out


if __name__ == "__main__":
    pass

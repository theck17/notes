# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-19 21:25:36
# Description:
class Solution:
    def magicalString(self, n: int) -> int:
        S = [1, 2, 2]
        idx = 2
        while len(S) < n:
            S += S[idx] * [(3 - S[-1])]
            idx += 1
        return S[:n].count(1)


if __name__ == "__main__":
    pass

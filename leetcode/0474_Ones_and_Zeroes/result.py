# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-18 11:16:40
# Description:
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        xy = [[s.count("0"), s.count("1")] for s in strs]

        @lru_cache(None)
        def dp(mm, nn, kk):
            if mm < 0 or nn < 0: return -float("inf")
            if kk == len(strs): return 0
            x, y = xy[kk]
            return max(1 + dp(mm - x, nn - y, kk + 1), dp(mm, nn, kk + 1))

        return dp(m, n, 0)


if __name__ == "__main__":
    pass

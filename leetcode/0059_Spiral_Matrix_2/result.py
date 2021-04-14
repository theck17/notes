# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-14 18:50:12
# Description:


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        lo = 0
        hi = n
        res = [[0] * n for _ in range(n)]
        cur = 1

        while lo <= hi:
            for top in range(lo, hi - 1):
                res[lo][top] = cur
                cur += 1

            for right in range(lo, hi - 1):
                res[right][hi - 1] = cur
                cur += 1

            for bot in range(hi - 1, lo, -1):
                res[hi - 1][bot] = cur
                cur += 1

            for left in range(hi - 1, lo, -1):
                res[left][lo] = cur
                cur += 1

            lo += 1
            hi -= 1

        if n % 2 != 0:
            res[n // 2][n // 2] = n * n

        return res


if __name__ == "__main__":
    pass

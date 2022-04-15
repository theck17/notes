# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-27 20:17:41
# Description:


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:

        f = [[0 for _ in range(rowIndex + 1)] for _ in range(2)]

        # rolling array
        for i in range(rowIndex + 1):
            f[i & 1][0] = f[i & 1][i] = 1
            for j in range(i):
                f[i & 1][j] = f[i - 1 & 1][j - 1] + f[i - 1 & 1][j]

        return f[rowIndex & 1]

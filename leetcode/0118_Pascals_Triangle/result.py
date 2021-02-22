# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-27 20:10:24
# Description:


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        l = [[0] * i for i in range(1, numRows + 1)]
        for i in range(len(l)):
            l[i][0] = 1
            l[i][-1] = 1
        for i in range(2, len(l)):
            for j in range(1, len(l[i]) - 1):
                l[i][j] = l[i - 1][j - 1] + l[i - 1][j]
        return l


if __name__ == "__main__":
    pass

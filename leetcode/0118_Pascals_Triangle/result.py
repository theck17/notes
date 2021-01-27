# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-27 20:10:24
# Description:


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []

        for i in range(0, numRows):
            a = []
            for j in range(0, i + 1):
                a.append(self.genPT(i, j))
            res.append(a)
        return res

    def genPT(self, i, j):
        if i == j or j == 0:
            return 1

        return self.genPT(i - 1, j - 1) + self.genPT(i - 1, j)


if __name__ == "__main__":
    pass

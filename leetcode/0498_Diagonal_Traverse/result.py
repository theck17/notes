# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-19 12:31:20
# Description:
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if not mat: return []
        m, n = len(mat), len(mat[0])
        levels = defaultdict(list)
        for i, j in product(range(m), range(n)):
            levels[i + j].append(mat[i][j])

        out = []
        for lev in range(m + n):
            out += levels[lev][::lev % 2 * 2 - 1]
        return out


if __name__ == "__main__":
    pass

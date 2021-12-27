# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-27 21:50:54
# Description:
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int,
                      c: int) -> List[List[int]]:
        m, n, count = len(mat), len(mat[0]), 0
        if m * n != r * c: return mat
        res = [[0] * c for _ in range(r)]
        for i, j in product(range(m), range(n)):
            res[count // c][count % c] = mat[i][j]
            count += 1
        return res


if __name__ == "__main__":
    pass

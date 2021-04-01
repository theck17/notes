# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-31 20:43:20
# Description:
import os
import sys


class Solution:
    def rotate(self, mat: List[List[int]]) -> None:

        if mat is None:
            return None

        n = len(mat)

        if n == 1:
            return mat

        for i in range(n):
            if len(mat[i]) != n:
                raise Exception("Matrix must be square")

        # Transpose the matrix
        for i in range(n):
            for j in range(i):
                mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

        # Swap columns
        for i in range(n):
            for j in range(n // 2):
                mat[i][j], mat[i][n - j - 1] = mat[i][n - j - 1], mat[i][j]


if __name__ == "__main__":
    pass

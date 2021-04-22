# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-21 19:08:15
# Description:

import os
import sys


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        Nrow = len(matrix)
        Ncol = len(matrix[0])

        changed = []
        for row in range(Nrow):
            for col in range(Ncol):
                coord = (row, col)
                if coord in changed:
                    continue
                if matrix[row][col] == 0 and coord not in changed:
                    for ir in range(Nrow):
                        if matrix[ir][col] != 0:
                            matrix[ir][col] = 0
                            changed.append((ir, col))
                    for ic in range(Ncol):
                        if matrix[row][ic] != 0:
                            matrix[row][ic] = 0
                            changed.append((row, ic))


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-17 08:09:37
# Description:

import os
import sys


class Solution:
    def back_tracking(self, grid, row, col, memo):
        if row == len(grid) - 1 and col == len(grid[0]) - 1:
            return 1 if grid[row][col] == 0 else 0

        if row > len(grid) - 1 or col > len(grid[0]) - 1:
            return 0

        if grid[row][col] == 1:
            return 0

        if row in memo and col in memo[row]:
            return memo[row][col]

        right = self.back_tracking(grid, row, col + 1, memo)
        down = self.back_tracking(grid, row + 1, col, memo)

        if not row in memo:
            memo[row] = {}

        memo[row][col] = right + down

        return memo[row][col]

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        memo = {}

        return self.back_tracking(obstacleGrid, 0, 0, memo)


if __name__ == "__main__":
    pass

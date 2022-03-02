# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-03-03 07:49:25
# Description:
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)

        dptable = [[0] * n for _ in range(n)]

        for i in range(n - 1):
            dptable[i][i + 1] = 0

        for row in range(n, -1, -1):
            for col in range(row + 2, n):

                for k in range(row + 1, col):

                    dptable[row][col] = max(
                        dptable[row][col], dptable[row][k] + dptable[k][col] +
                        nums[row] * nums[k] * nums[col])

        return dptable[0][-1]


if __name__ == "__main__":
    pass

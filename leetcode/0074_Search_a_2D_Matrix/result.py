# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-23 19:02:11
# Description:

import os
import sys


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        for data in matrix:
            start = 0
            end = len(data) - 1
            if data[start] <= target <= data[end]:
                while start <= end:
                    mid = (start + end) // 2
                    if data[mid] == target:
                        return True
                    elif data[mid] < target:
                        start = mid + 1
                    else:
                        end = mid - 1
                break
        return False


if __name__ == "__main__":
    pass

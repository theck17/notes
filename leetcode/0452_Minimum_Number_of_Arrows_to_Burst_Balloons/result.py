# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-11 20:58:29
# Description:
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        n, count = len(points), 1
        if n == 0: return 0
        curr = points[0]

        for i in range(n):
            if curr[1] < points[i][0]:
                count += 1
                curr = points[i]

        return count


if __name__ == "__main__":
    pass

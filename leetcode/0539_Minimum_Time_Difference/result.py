# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-17 09:28:20
# Description:
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def toint(s):
            h, m = s.split(':')
            return int(h) * 60 + int(m)

        arr = sorted(map(toint, timePoints))

        mini = sys.maxsize
        for i in range(len(arr) - 1):
            mini = min(arr[i + 1] - arr[i], mini)
            if mini == 0:
                return 0

        mini = min(mini, 24 * 60 - (arr[-1] - arr[0]))
        return mini


if __name__ == "__main__":
    pass

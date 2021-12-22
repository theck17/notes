# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-22 20:28:26
# Description:
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int],
                             duration: int) -> int:
        n, out = len(timeSeries), 0
        if n == 0: return 0
        for i in range(n - 1):
            out += min(timeSeries[i + 1] - timeSeries[i], duration)
        return out + duration


if __name__ == "__main__":
    pass

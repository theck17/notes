# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-29 21:42:01
# Description: 

from heapq import *

class MedianFinder:
    def __init__(self):
        self.heaps = [], []

    def addNum(self, num: int) -> None:
        small, large = self.heaps
        heappush(small, -heappushpop(large, num))
        if len(large) < len(small):
            heappush(large, -heappop(small))

    def findMedian(self) -> float:
        small, large = self.heaps
        if len(large) > len(small):
            return float(large[0])
        return (large[0] - small[0]) / 2.0


if __name__ == "__main__":
   pass


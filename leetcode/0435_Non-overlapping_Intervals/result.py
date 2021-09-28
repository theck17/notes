# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-28 22:33:18
# Description: 
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals: return 0
        intervals.sort(key=lambda x: x[1])
        currEnd, cnt = intervals[0][-1], 0
        for x in intervals[1:]:
            if x[1] < currEnd:
                cnt += 1
                currEnd = min(currEnd, x[-1])
            else:
                currEnd = x[-1]
        return cnt

if __name__ == "__main__":
   pass


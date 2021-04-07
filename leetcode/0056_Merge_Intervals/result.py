# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-07 20:34:19
# Description:


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        i = intervals
        i.sort(key=lambda x: x[0])
        res = [intervals[0]]
        for pos in range(1, len(i)):
            # no overlap:
            if res[-1][1] < i[pos][0]:
                res.append(i[pos])
            # partial overlap
            elif res[-1][1] >= i[pos][0] and res[-1][1] <= i[pos][1]:
                merged = [res[-1][0], i[pos][1]]
                res.pop(-1)
                res.append(merged)
        return res


if __name__ == "__main__":
    pass

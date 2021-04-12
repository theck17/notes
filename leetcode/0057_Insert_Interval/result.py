# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-12 18:35:15
# Description:


class Solution:
    def insert(self, intervals: List[List[int]],
               newInterval: List[int]) -> List[List[int]]:

        res, i = [], 0

        for interval in intervals:
            if interval[1] < newInterval[0]:
                res.append(interval)
            elif interval[0] > newInterval[1]:
                res.append(newInterval)
                newInterval = interval
            elif interval[1] >= newInterval[0] or newInterval[1] >= interval[0]:
                newInterval = [
                    min(interval[0], newInterval[0]),
                    max(interval[1], newInterval[1])
                ]

        res.append(newInterval)
        return res


if __name__ == "__main__":
    pass

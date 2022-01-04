# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-04 21:25:16
# Description:
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        # Group indexes by element type
        d = defaultdict(list)
        for i, x in enumerate(nums):
            d[x].append(i)
        # Find highest Degree
        m = max([len(v) for v in d.values()])
        # Find shortest span for max. degree
        best = len(nums)
        for v in d.values():
            if len(v) == m:
                best = min(best, v[-1] - v[0] + 1)
        return best


if __name__ == "__main__":
    pass

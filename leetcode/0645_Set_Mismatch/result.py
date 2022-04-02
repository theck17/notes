# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-03 09:00:07
# Description:
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        seen = defaultdict(int)
        for x in nums:
            seen[x] += 1
        miss = dup = 0
        for i in range(1, n + 1):
            if i not in seen:
                miss = i
            elif seen[i] == 2:
                dup = i
        return [dup, miss]

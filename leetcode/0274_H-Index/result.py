# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-24 20:45:06
# Description:
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        n = len(citations)
        for i in range(n):
            if citations[i] >= (n - i):
                return n - i
        return 0


if __name__ == "__main__":
    pass

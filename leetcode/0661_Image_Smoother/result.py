# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-03-01 09:42:38
# Description:
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        res = [[1] * len(M[0]) for _ in range(len(M))]

        for row in range(len(M)):
            for col in range(len(M[0])):
                d = [-1, 0, 1]

                vad_m = [M[row + r][col + c] \
                         for r in d \
                         for c in d \
                         if 0 <= row + r <= len(M) - 1 and \
                         0 <= col + c <= len(M[0]) - 1]

                avg = int(sum(vad_m) / len(vad_m))

                res[row][col] = int(avg)
        return res

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-17 15:14:39
# Description:
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int,
                    G: int, H: int) -> int:
        overlap = max(min(C, G) - max(A, E), 0) * max(min(D, H) - max(B, F), 0)
        return (A - C) * (B - D) + (E - G) * (F - H) - overlap

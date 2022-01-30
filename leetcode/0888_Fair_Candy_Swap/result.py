# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-30 11:03:56
# Description:
class Solution:
    def fairCandySwap(self, aliceSizes: List[int],
                      bobSizes: List[int]) -> List[int]:
        n = (sum(aliceSizes) - sum(bobSizes)) // 2
        aliceSizes = list(map(lambda a: a - n, aliceSizes))
        b = (list(set(aliceSizes) & set(bobSizes)))[0]
        return [b + n, b]


if __name__ == "__main__":
    pass

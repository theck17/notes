# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-15 17:10:08
# Description:
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for i, x in enumerate(flowerbed):
            if (not x and (i == 0 or flowerbed[i - 1] == 0)
                    and (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0)):
                n -= 1
                flowerbed[i] = 1
        return n <= 0


if __name__ == "__main__":
    pass

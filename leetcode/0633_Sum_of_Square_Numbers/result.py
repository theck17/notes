# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-22 18:57:07
# Description:
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        sq = set()
        count = int(math.sqrt(c))
        # use (count + 1) because first index is 0
        for i in range(count + 1):
            sq.add(i ** 2)

        for n in sq:
            if c - n in sq:
                return True

        return False


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-11 23:41:24
# Description:
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i = 1
        while (num > 0):
            num -= i
            i += 2
        return num == 0


if __name__ == "__main__":
    pass

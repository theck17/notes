# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-01 20:37:38
# Description:


class Solution:
    def findNthDigit(self, n: int) -> int:
        start, digits = 1, 1
        while n > 9 * start * digits:
            n -= 9 * start * digits
            start = 10 ** digits
            digits += 1
        return int(str(start + (n - 1) // digits)[(n - 1) % digits])


if __name__ == "__main__":
    pass

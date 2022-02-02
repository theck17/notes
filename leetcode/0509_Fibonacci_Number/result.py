# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-02 10:36:54
# Description:
class Solution:
    def fib(self, n: int) -> int:
        if n < 2: return n
        a, b = 0, 1
        for _ in range(1, n):
            a, b = b, a + b
        return b


if __name__ == "__main__":
    pass

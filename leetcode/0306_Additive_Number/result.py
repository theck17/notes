# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-10 11:56:49
# Description:


class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)
        for i, j in itertools.combinations(range(1, n), 2):
            a, b = num[:i], num[i:j]
            if b != str(int(b)):
                continue
            while j < n:
                c = str(int(a) + int(b))
                if not num.startswith(c, j):
                    break
                j += len(c)
                a, b = b, c
            if j == n:
                return True
        return False


if __name__ == "__main__":
    pass

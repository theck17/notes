# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-15 08:14:38
# Description:
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        i = 1
        n = bin(n)[2:]
        for i in range(1, len(n)):
            if n[i - 1] == n[i]:
                return False
        return True


if __name__ == "__main__":
    pass

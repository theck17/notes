# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-09 09:17:25
# Description:
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        lentitle = len(columnTitle)
        n2 = 0
        for i in range(0, lentitle):
            n1 = ord(columnTitle[i]) - 64
            n2 = 26 * n2 + n1
        return n2


if __name__ == "__main__":
    pass

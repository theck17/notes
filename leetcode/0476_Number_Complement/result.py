# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-05 16:24:22
# Description:
class Solution:
    def findComplement(self, num: int) -> int:
        i = 1
        while i <= num:
            i = i << 1
        return (i - 1) ^ num


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-06 21:23:02
# Description:
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        t = iter(t)
        return all(c in t for c in s)


if __name__ == "__main__":
    pass

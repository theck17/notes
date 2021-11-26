# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-26 19:00:34
# Description:
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        if not s:
            return False
        ss = (s + s)[1:-1]
        return ss.find(s) != -1


if __name__ == "__main__":
    pass

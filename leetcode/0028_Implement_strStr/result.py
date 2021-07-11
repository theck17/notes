# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-07-11 12:33:27
# Description:


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(0, len(haystack) - len(needle) + 1):
            if haystack[i:i + len(needle)] == needle:
                return i
        return -1


if __name__ == "__main__":
    pass

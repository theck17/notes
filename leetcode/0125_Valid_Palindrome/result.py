# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-06 16:40:16
# Description:
class Solution:
    def isPalindrome(self, s: str) -> bool:
        beg, end = 0, len(s) - 1
        while beg <= end:
            while not s[beg].isalnum() and beg < end:
                beg += 1
            while not s[end].isalnum() and beg < end:
                end -= 1
            if s[beg] == s[end] or s[beg].upper() == s[end].upper():
                beg, end = beg + 1, end - 1
            else:
                return False
        return True


if __name__ == "__main__":
    pass

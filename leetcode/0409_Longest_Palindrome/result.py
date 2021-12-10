# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-10 20:34:58
# Description:
class Solution:
    def longestPalindrome(self, s: str) -> int:
        hash = set()
        for c in s:
            if c not in hash:
                hash.add(c)
            else:
                hash.remove(c)
        return len(s) - len(hash) + 1 if len(hash) > 0 else len(s)


if __name__ == "__main__":
    pass

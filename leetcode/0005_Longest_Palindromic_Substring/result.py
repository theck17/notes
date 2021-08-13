# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-13 21:52:14
# Description:
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        for i in range(len(s)):
            res = max(self.helper(s, i, i),
                      self.helper(s, i, i + 1),
                      res,
                      key=len)

        return res

    def helper(self, s, l, r):

        while 0 <= l and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l + 1:r]


if __name__ == "__main__":
    pass

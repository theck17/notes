# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-08 19:02:34
# Description:
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        self.dfs(s, [], res)
        return res

    def dfs(self, s, path, res):
        if not s:
            res.append(path)
        for i in range(1, len(s) + 1):
            if self.isPalindrome(s[:i]):
                self.dfs(s[i:], path + [s[:i]], res)

    def isPalindrome(self, s):
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    def isPalindrome1(self, s):
        return s == s[::-1]


if __name__ == "__main__":
    pass

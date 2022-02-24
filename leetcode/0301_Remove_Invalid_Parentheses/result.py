# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-24 10:22:54
# Description:
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        self.res = []
        self.visited = set([s])
        self.dfs(s, self.calc(s))
        return self.res

    def dfs(self, s, n):
        if n == 0:
            self.res.append(s)
            return
        for i in range(len(s)):
            if s[i] in ('(', ')'):
                new_s = s[:i] + s[i + 1:]
                new_n = self.calc(new_s)
                if new_s not in self.visited and new_n < n:
                    self.visited.add(new_s)
                    self.dfs(new_s, new_n)

    def calc(self, s):
        # calculate how many redundant left / right parentheses
        l = 0
        r = 0
        for c in s:
            if c == '(':
                l += 1
            elif c == ')':
                if l:
                    l -= 1
                else: # not match any left parenthes
                    r += 1
        return l + r


if __name__ == "__main__":
    pass

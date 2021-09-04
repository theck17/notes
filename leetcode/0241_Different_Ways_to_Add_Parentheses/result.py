# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-04 17:24:45
# Description:
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        m = {}
        return self.dfs(expression, m)

    def dfs(self, expression, m):
        if expression in m:
            return m[expression]
        if expression.isdigit():
            m[expression] = int(expression)
            return [int(expression)]
        ret = []
        for i, c in enumerate(expression):
            if c in "+-*":
                l = self.diffWaysToCompute(expression[:i])
                r = self.diffWaysToCompute(expression[i + 1:])
                ret.extend(eval(str(x) + c + str(y)) for x in l for y in r)
        m[expression] = ret
        return ret


if __name__ == "__main__":
    pass

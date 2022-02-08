# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-08 11:45:01
# Description:
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        stack = []
        for i, el in enumerate(ops):
            if el == '+':
                stack.append(stack[-1] + stack[-2])
            elif el == 'D':
                stack.append(stack[-1] * 2)
            elif el == 'C':
                stack.pop()
            else:
                stack.append(int(el))
        return sum(stack)


if __name__ == "__main__":
    pass

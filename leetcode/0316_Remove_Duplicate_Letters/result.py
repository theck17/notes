# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-03 20:28:29
# Description:
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last_occ = {c: i for i, c in enumerate(s)}
        stack = ["!"]
        Visited = set()

        for i, symbol in enumerate(s):
            if symbol in Visited: continue

            while (symbol < stack[-1] and last_occ[stack[-1]] > i):
                Visited.remove(stack.pop())

            stack.append(symbol)
            Visited.add(symbol)
        return "".join(stack)[1:]


if __name__ == "__main__":
    pass

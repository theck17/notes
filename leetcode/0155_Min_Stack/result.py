# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-13 21:45:34
# Description:
class MinStack:
    def __init__(self):
        self.q = []

    def push(self, val: int) -> None:
        curMin = self.getMin()
        if curMin == None or val < curMin:
            curMin = val
        self.q.append((val, curMin))

    def pop(self) -> None:
        self.q.pop()

    def top(self) -> int:
        if len(self.q) == 0:
            return None
        else:
            return self.q[len(self.q) - 1][0]

    def getMin(self) -> int:
        if len(self.q) == 0:
            return None
        else:
            return self.q[len(self.q) - 1][1]


if __name__ == "__main__":
    pass

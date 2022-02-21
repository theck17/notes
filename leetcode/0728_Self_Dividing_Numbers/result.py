# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-21 10:57:43
# Description:
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        numList = []
        for num in range(left, right + 1):
            numCopy = num
            selfDividing = True
            while num:
                if num % 10 != 0 and numCopy % (num % 10) == 0:
                    num = num // 10
                    continue
                else:
                    selfDividing = False
                    break
            if selfDividing:
                numList.append(numCopy)
        return numList


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-21 10:50:34
# Description:
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        inputNum = x
        newNum = 0
        while x > 0:
            newNum = newNum * 10 + x % 10
            x = x // 10
        return newNum == inputNum


if __name__ == "__main__":
    pass

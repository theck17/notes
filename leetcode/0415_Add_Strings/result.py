# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-22 16:42:25
# Description:
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        num1, num2 = num1[::-1], num2[::-1]
        num3 = ''
        carry = i = 0
        l1, l2 = len(num1), len(num2)
        l3 = max(l1, l2)
        while i < l3 or carry:
            dig1 = int(num1[i]) if i < l1 else 0
            dig2 = int(num2[i]) if i < l2 else 0
            dig3 = (dig1 + dig2 + carry) % 10
            carry = (dig1 + dig2 + carry) // 10
            num3 += str(dig3)
            i += 1
        return num3[::-1]


if __name__ == "__main__":
    pass

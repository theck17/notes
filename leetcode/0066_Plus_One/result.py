# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-21 21:30:34
# Description:

import os, sys


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        token = 1
        for i in range(len(digits) - 1, -1, -1):
            sum = digits[i] + token
            digits[i] = sum % 10
            token = sum // 10
        if token > 0:
            return [token] + digits
        else:
            return digits


if __name__ == "__main__":
    pass

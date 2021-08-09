# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-09 19:41:36
# Description:
class Solution:
    def intToRoman(self, num: int) -> str:
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        numerals = [
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV",
            "I"
        ]
        res, i = "", 0
        while num:
            res += (num // values[i]) * numerals[i]
            num %= values[i]
            i += 1
        return res


if __name__ == "__main__":
    pass

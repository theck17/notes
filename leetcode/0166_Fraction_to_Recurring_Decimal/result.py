# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-14 21:20:08
# Description:
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator % denominator == 0:
            return str(numerator // denominator)
        sign = '' if numerator * denominator >= 0 else '-'
        numerator, denominator = abs(numerator), abs(denominator)
        res = sign + str(numerator // denominator) + '.'
        numerator %= denominator
        i, part = 0, ''
        m = {numerator: i}
        while numerator % denominator:
            numerator *= 10
            i += 1
            rem = numerator % denominator
            part += str(numerator // denominator)
            if rem in m:
                part = part[:m[rem]] + '(' + part[m[rem]:] + ')'
                return res + part
            m[rem] = i
            numerator = rem
        return res + part


if __name__ == "__main__":
    pass

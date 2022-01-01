# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-01 09:43:12
# Description:
class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        S = s.upper().replace('-', '')
        size = len(S)
        s1 = k if size % k == 0 else size % k
        res = S[:s1]
        while s1 < size:
            res += '-' + S[s1:s1 + k]
            s1 += k
        return res


if __name__ == "__main__":
    pass

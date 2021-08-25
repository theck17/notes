# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-25 21:38:07
# Description:
class Solution:
    def toLowerCase(self, s: str) -> str:
        return "".join(chr(ord(c) + 32) if "A" <= c <= "Z" else c for c in s)


if __name__ == "__main__":
    pass

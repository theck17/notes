# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-07-10 16:17:58
# Description:


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.split()
        if s:
            return len(s[-1])
        return 0

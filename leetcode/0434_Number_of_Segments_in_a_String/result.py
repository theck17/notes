# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-23 19:31:24
# Description:
class Solution:
    def countSegments(self, s: str) -> int:
        if len(s.strip()) < 1:
            return 0

        count = 0
        for i in range(len(s.strip()) - 1):
            if s[i] == " " and s[i + 1] != " ":
                count += 1
        return count + 1


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-14 17:05:07
# Description:
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        curr, prev, ans = 1, 0, 0
        for i in range(1, len(s)):
            if s[i] == s[i - 1]: curr += 1
            else:
                ans += min(curr, prev)
                prev, curr = curr, 1
        return ans + min(curr, prev)


if __name__ == "__main__":
    pass

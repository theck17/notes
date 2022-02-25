# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-25 09:07:11
# Description:
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        l = 0
        output = 0
        for r in range(len(s)):
            if s[r] not in seen:
                output = max(output, r - l + 1)
            else:
                if seen[s[r]] < l:
                    output = max(output, r - l + 1)
                else:
                    l = seen[s[r]] + 1
            seen[s[r]] = r
        return output


if __name__ == "__main__":
    pass

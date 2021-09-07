# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-07 20:41:44
# Description: 
class Solution:
    def numDecodings(self, s: str) -> int:
        @lru_cache(None)
        def dp(i):
            if i == len(s): return 1
            ans = 0
            if s[i] != '0':  # Single digit
                ans += dp(i + 1)
            if i + 1 < len(s) and (s[i] == '1' or s[i] == '2' and ord(s[i + 1]) <= ord('6')):  # Two digits
                ans += dp(i + 2)
            return ans

        return dp(0)

if __name__ == "__main__":
   pass


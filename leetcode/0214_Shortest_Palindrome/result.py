# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-03-02 10:03:21
# Description:
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        BASE, MOD = 26, 10 ** 9 + 7 # N of lowercase alphabets : 25
        ans = 0
        front, back = 0, 0
        pow_base = 1
        for i, c in enumerate(s):
            front = (front * BASE + ord(c) - ord('a')) % MOD
            back = (back + (ord(c) - ord('a')) * pow_base) % MOD
            pow_base *= BASE
            if front == back:
                # double check
                if s[:i + 1] == s[:i + 1][::-1]:
                    ans = i + 1
        return s[ans:][::-1] + s


if __name__ == "__main__":
    pass

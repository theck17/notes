# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-30 21:25:58
# Description:
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        Num_cap, n = 0, len(word)
        for letter in word:
            Num_cap += letter.isupper()
        if Num_cap == 0 or Num_cap == n or Num_cap == 1 and word[0].isupper():
            return True
        return False

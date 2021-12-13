# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-13 19:12:08
# Description:
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        a = set('qwertyuiop')
        b = set('asdfghjkl')
        c = set('zxcvbnm')
        ans = []
        for word in words:
            t = set(word.lower())
            if a & t == t:
                ans.append(word)
            if b & t == t:
                ans.append(word)
            if c & t == t:
                ans.append(word)
        return ans


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-30 22:23:43
# Description: 
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        dic = {}
        for ch in s:
            dic[ch] = dic.get(ch, 0) + 1
        for ch in t:
            if dic.get(ch, 0) == 0:
                return ch
            else:
                dic[ch] -= 1

if __name__ == "__main__":
   pass


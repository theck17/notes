# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-07-23 21:27:30
# Description: 
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic1, dic2 = {}, {}
        for item in s:
            dic1[item] = dic1.get(item, 0) + 1
        for item in t:
            dic2[item] = dic2.get(item, 0) + 1
        return dic1 == dic2

if __name__ == "__main__":
   pass


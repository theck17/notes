# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-07-24 21:28:54
# Description: 

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        # split str into single words.
        slist = s.split()
        
        # here we need to consider the len difference
        # eg: pattern:"aaa" str:"aa aa aa aa"
        if len(pattern) != len(slist):
            return False
        
        # just like we do in isomorphic problem.
        return (len(set(pattern)) == len(set(slist)) == len(set(zip(pattern, slist))))

if __name__ == "__main__":
   pass


# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-07-09 19:40:06
# Description: 

class Solution:
    def isValid(self, s: str) -> bool:
        n = len(s)
        if n == 0:
            return True
        
        if n % 2 != 0:
            return False
            
        while '()' in s or '{}' in s or '[]' in s:
            s = s.replace('{}','').replace('()','').replace('[]','')
        
        if s == '':
            return True
        else:
            return False


if __name__ == "__main__":
   pass


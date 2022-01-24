# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-20 11:10:13
# Description: 
class Solution:
    def addDigits(self, num: int) -> int:
        if num%9 == 0 and num!=0:
            return 9
        return (num%9)

if __name__ == "__main__":
   pass


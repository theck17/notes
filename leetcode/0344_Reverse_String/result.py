# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-14 20:08:06
# Description: 
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        swap = ""
        n = len(s)
        for i in range(int(n/2)):
            swap = s[i]
            s[i] = s[n-1-i]
            s[n-1-i] = swap
        print(s)
        

if __name__ == "__main__":
   pass


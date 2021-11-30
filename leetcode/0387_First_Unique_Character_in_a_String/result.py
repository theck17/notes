# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-30 21:55:47
# Description: 
        d = {}
        for l in s:
            if l not in d: d[l] = 1
            else: d[l] += 1
        
        index = -1
        for i in range(len(s)):
            if d[s[i]] == 1:
                index = i
                break
        
        return index

if __name__ == "__main__":
   pass


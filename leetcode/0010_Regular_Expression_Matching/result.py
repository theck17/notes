# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-31 21:25:54
# Description: 
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[True] + [False] * len(s)]
        for i, pc in enumerate(p):
            row = [pc == '*' and dp[-2][0]]
            for j, sc in enumerate(s):
                if pc == '.':
                    row.append(dp[-1][j])
                elif pc == '*':
                    row.append(dp[-2][j + 1] or ((p[i - 1] == '.' or p[i - 1] == sc) and row[j]))
                else:
                    row.append(dp[-1][j] and pc == sc)
            dp.append(row)
        return dp[-1][-1]

if __name__ == "__main__":
   pass


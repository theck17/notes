# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-26 17:59:55
# Description: 
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n, right_max = len(temperatures), float('-inf')
        res = [0] * n
        for i in range(n-1, -1, -1):
            t = temperatures[i]
            if right_max <= t:
                right_max = t
            else:
                days = 1
                while temperatures[i+days] <= t:
                    days += res[i+days]
                res[i] = days
        return resclass Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n, right_max = len(temperatures), float('-inf')
        res = [0] * n
        for i in range(n-1, -1, -1):
            t = temperatures[i]
            if right_max <= t:
                right_max = t
            else:
                days = 1
                while temperatures[i+days] <= t:
                    days += res[i+days]
                res[i] = days
        return res

if __name__ == "__main__":
   pass


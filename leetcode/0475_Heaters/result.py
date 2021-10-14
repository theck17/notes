# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-14 20:42:14
# Description:
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        heaters = [float('-inf')] + heaters + [float('inf')
                                               ] # add 2 fake heaters
        ans, i = 0, 0
        for house in houses:
            while house > heaters[i + 1]: # search to put house between heaters
                i += 1
            dis = min(house - heaters[i], heaters[i + 1] - house)
            ans = max(ans, dis)
        return ans


if __name__ == "__main__":
    pass

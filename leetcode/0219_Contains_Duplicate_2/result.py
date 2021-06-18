# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-06-18 18:49:16
# Description: 

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dic = {}
        for i, v in enumerate(nums):
            if v in dic and i - dic[v] <= k:
                return True
            dic[v] = i
        return False




if __name__ == "__main__":
   pass


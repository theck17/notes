# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-08 19:43:29
# Description: 

import os, sys

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        arr = set(range(1, len(nums) + 1))
        for num in nums:
          if num in arr:
            arr.remove(num)
        return list(arr)




if __name__ == "__main__":
   pass


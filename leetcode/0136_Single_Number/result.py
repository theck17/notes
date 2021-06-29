# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-06-28 19:59:25
# Description:


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dic = {}
        for num in nums:
            dic[num] = dic.get(num, 0) + 1
        for key, val in dic.items():
            if val == 1:
                return key

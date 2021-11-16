# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-16 21:11:11
# Description:
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        count = 0
        result = 0
        dict_seen = {0: -1}
        for i in range(len(nums)):
            n = nums[i]
            if n == 0:
                count -= 1
            if n == 1:
                count += 1
            if count in dict_seen:
                result = max(result, i - dict_seen[count])
            else:
                dict_seen[count] = i

        return result


if __name__ == "__main__":
    pass

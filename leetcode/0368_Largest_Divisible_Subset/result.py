# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-20 16:05:54
# Description:
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        opt = [[nums[i]] for i in range(len(nums))]
        for i in range(1, len(nums)):
            for j in range(i - 1, -1, -1):
                if nums[i] % nums[j] == 0:
                    if len(opt[j]) + 1 > len(opt[i]):
                        opt[i] = list(opt[j])
                        opt[i].append(nums[i])
        maxcount = 0
        ans = []
        for temp in opt:
            if len(temp) > maxcount:
                ans = temp
                maxcount = len(temp)
        return ans


if __name__ == "__main__":
    pass

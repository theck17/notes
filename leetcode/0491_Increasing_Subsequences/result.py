# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-12 20:01:29
# Description:
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.helper(ans, nums, [], 0)
        return ans

    def helper(self, ans, nums, temp, pos):
        if len(temp) >= 2:
            ans.append(temp)
        visited = set()
        for i in range(pos, len(nums)):
            if not temp or temp[-1] <= nums[i]:
                if nums[i] not in visited:
                    self.helper(ans, nums, temp + [nums[i]], i + 1)
                    visited.add(nums[i])


if __name__ == "__main__":
    pass

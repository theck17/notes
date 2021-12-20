# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-20 18:48:25
# Description:
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        nums_sum = sum(nums)
        if (nums_sum + S) % 2 == 1 or abs(S) > nums_sum:
            return 0
        target_sum = (nums_sum + S) / 2
        dp = [1] + [0] * target_sum
        for num in nums:
            for s in range(target_sum, num - 1, -1):
                dp[s] += dp[s - num]
        return dp[target_sum]


if __name__ == "__main__":
    pass

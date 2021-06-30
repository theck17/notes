# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-06-30 19:32:09
# Description:


class Solution:
    def rob(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        if length == 1:
            return nums[0]
        if length == 2:
            return max(nums)

        dp = [0] * length # assign dp array
        dp[0], dp[1] = nums[0], max(nums[0], nums[1])

        for i in range(2, length):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        print(dp)

        return max(dp)


if __name__ == "__main__":
    pass

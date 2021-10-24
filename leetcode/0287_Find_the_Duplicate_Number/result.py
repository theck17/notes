# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-24 12:31:36
# Description:
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        mid = (high + low) / 2
        while high - low > 1:
            count = 0
            for k in nums:
                if mid < k <= high:
                    count += 1
            if count > high - mid:
                low = mid
            else:
                high = mid
            mid = (high + low) / 2
        return high


if __name__ == "__main__":
    pass

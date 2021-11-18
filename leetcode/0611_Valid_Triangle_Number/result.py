# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-18 21:23:27
# Description:
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums, count, n = sorted(nums), 0, len(nums)
        for i in range(2, n):
            left, right = 0, i - 1
            while left < right:
                if nums[left] + nums[right] > nums[i]:
                    count += (right - left)
                    right -= 1
                else:
                    left += 1
        return count


if __name__ == "__main__":
    pass

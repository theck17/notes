# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-05-08 18:33:04
# Description:


class Solution:
    def search(self, nums, target):
        if not nums:
            return False
        l, r = 0, len(nums) - 1
        while l < r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                return True
            if nums[mid] < nums[r]:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            elif nums[mid] > nums[r]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                r -= 1
        return nums[l] == target


if __name__ == "__main__":
    pass

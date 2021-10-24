# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-24 12:31:36
# Description:
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        beg, end = 1, len(nums) - 1
        while beg + 1 <= end:
            mid, count = (beg + end) // 2, 0
            for num in nums:
                if num <= mid: count += 1
            if count <= mid:
                beg = mid + 1
            else:
                end = mid
        return end


if __name__ == "__main__":
    pass

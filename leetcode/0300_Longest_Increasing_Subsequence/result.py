# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-16 19:54:41
# Description:
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            ins_idx = bisect.bisect_left(nums, nums[i], hi=i)
            if ins_idx != i:
                nums[ins_idx], nums[i] = nums[i], float(inf)
        return nums.index(float(inf)) if float(inf) in nums else len(nums)


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-14 22:13:35
# Description:


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        cur = 0

        for pos in range(1, len(nums)):
            if nums[pos] != nums[cur]:
                cur += 1
                nums[cur] = nums[pos]

        return cur + 1


if __name__ == "__main__":
    pass

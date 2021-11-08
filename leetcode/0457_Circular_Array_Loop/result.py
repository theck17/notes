# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-08 20:55:20
# Description:
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        if not nums or len(nums) < 2:
            return False

        n = len(nums)
        for i in range(n):
            if type(nums[i]) != int:
                continue
            if nums[i] % n == 0:
                continue

            direction = (nums[i] > 0)

            mark = str(i)
            while (type(nums[i])
                   == int) and (direction ^
                                (nums[i] < 0)) and (nums[i] % n != 0):
                jump = nums[i]
                nums[i] = mark
                i = (i + jump) % n

            if nums[i] == mark:
                return True

        return False


if __name__ == "__main__":
    pass

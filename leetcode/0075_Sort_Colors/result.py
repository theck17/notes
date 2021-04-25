# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-25 19:44:31
# Description:


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        red, white, blue = 0, 0, 0

        for i in nums:
            if i == 0:
                red += 1
            elif i == 1:
                white += 1
            elif i == 2:
                blue += 1

        result = [0] * red + [1] * white + [2] * blue

        for i, num in enumerate(nums):
            nums[i] = result[i]


if __name__ == "__main__":
    pass

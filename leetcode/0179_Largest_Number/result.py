# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-01 21:56:47
# Description:
from functools import cmp_to_key


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def cmp_func(x, y):
            """Sorted by value of concatenated string increasingly."""
            if x + y > y + x:
                return 1
            elif x == y:
                return 0
            else:
                return -1

        # Build nums contains all numbers in the String format.
        nums = [str(num) for num in nums]

        # Sort nums by cmp_func decreasingly.
        nums.sort(key=cmp_to_key(cmp_func), reverse=True)

        # Remove leading 0s, if empty return '0'.
        return ''.join(nums).lstrip('0') or '0'


if __name__ == "__main__":
    pass

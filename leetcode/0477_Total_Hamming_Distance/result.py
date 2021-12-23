# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-23 19:13:42
# Description:
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        l = len(nums)
        bits_count = [0] * 32

        for num in nums:
            idx = 0
            while num > 0:
                if num & 1 == 1:
                    bits_count[idx] += 1
                num >>= 1
                idx += 1
        return sum([x * (l - x) for x in bits_count])


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-13 11:01:01
# Description:
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])


if __name__ == "__main__":
    pass

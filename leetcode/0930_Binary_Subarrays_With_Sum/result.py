# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-20 19:15:41
# Description:
class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        c = collections.Counter({0: 1})
        psum = res = 0
        for i in nums:
            psum += i
            res += c[psum - goal]
            c[psum] += 1
        return res


if __name__ == "__main__":
    pass

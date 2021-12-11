# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-11 12:18:14
# Description:
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        size = len(primes)
        ugly, dp, index, ugly_nums = 1, [1], [0] * size, [1] * size
        for i in range(1, n):
            for j in range(0, size):
                if ugly_nums[j] == ugly:
                    ugly_nums[j] = dp[index[j]] * primes[j]
                    index[j] += 1
            ugly = min(ugly_nums)
            dp.append(ugly)
        return dp[-1]


if __name__ == "__main__":
    pass

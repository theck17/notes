# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-15 00:07:14
# Description:


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = set()
        for i in range(0, len(nums) - 1):
            # Reduce the problem to two sum(0)
            two_sum = -nums[i]
            cache = set()
            for num in nums[i + 1:]:
                remaining = two_sum - num
                if remaining in cache:
                    #sorting to create unique tuples
                    triplet = tuple(sorted([nums[i], remaining, num]))
                    # using tuple in a set will eliminate duplicates combinations
                    result.add(triplet)
                else:
                    cache.add(num)
        return result


if __name__ == "__main__":
    pass

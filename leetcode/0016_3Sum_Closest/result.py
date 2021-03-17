# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-17 19:36:41
# Description:


class Solution:
    def two_sum(self, nums, rest_sum, start_from, sums):
        i = start_from + 1
        j = len(nums) - 1

        while i < j:
            sum2 = nums[i] + nums[j]
            if sum2 < rest_sum:
                i += 1
            elif sum2 > rest_sum:
                j -= 1
            else:
                # early exit so don't need dictionary any more
                return 0
            signed_dist = sum2 - rest_sum
            sums[signed_dist] = signed_dist
        return None

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        # values are the same as keys, so could just use a list, but dictionary runs faster
        sums = {}
        for i in range(0, len(nums)):
            best_sum = self.two_sum(nums, target - nums[i], i, sums)
            if best_sum is not None:
                return target
        min_dist = min(sums, key=lambda x: abs(sums[x]))
        res = min_dist + target
        return res


if __name__ == "__main__":
    pass

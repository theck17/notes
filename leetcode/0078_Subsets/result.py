# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-27 21:41:14
# Description:


class Solution(object):
    def subsets(self, nums):
        ret = []
        self.dfs(nums, [], ret)
        return ret

    def dfs(self, nums, path, ret):
        ret.append(path)
        for i in range(len(nums)):
            self.dfs(nums[i + 1:], path + [nums[i]], ret)

    # Bit Manipulation
    def subsets2(self, nums):
        res = []
        nums.sort()
        for i in xrange(1 << len(nums)):
            tmp = []
            for j in xrange(len(nums)):
                if i & 1 << j: # if i >> j & 1:
                    tmp.append(nums[j])
            res.append(tmp)
        return res

    # Iteratively
    def subsets(self, nums):
        res = [[]]
        for num in sorted(nums):
            res += [item + [num] for item in res]
        return res


if __name__ == "__main__":
    pass

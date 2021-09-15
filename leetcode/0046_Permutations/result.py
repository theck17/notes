# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-15 19:10:22
# Description:
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        lev, avail, lev_node = 0, nums, []
        N = len(nums)

        def dfs(lev, avail, lev_node):
            if lev == N:
                res.append(lev_node)
                return
            for i in range(len(avail)):
                dfs(lev + 1, avail[:i] + avail[i + 1:], lev_node + [avail[i]])

        dfs(lev, avail, lev_node)
        return (res)


if __name__ == "__main__":
    pass

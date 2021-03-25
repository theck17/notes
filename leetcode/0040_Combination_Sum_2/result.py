# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-24 19:24:54
# Description:

import os
import sys


class Solution:
    def combinationSum2(self, candidates: List[int],
                        target: int) -> List[List[int]]:
        def dfs(candidates: List[int], target: int, cur_path: List[int],
                ans: List[List[List[int]]]):
            if target < 0:
                return
            if target == 0:
                ans.append(cur_path)
                return
            for index, num in enumerate(candidates):
                if index > 0 and candidates[index] == candidates[index - 1]:
                    continue
                if num > target:
                    continue
                dfs(candidates[index + 1:], target - num, cur_path + [num],
                    ans)

        ans = []
        dfs(sorted([x for x in candidates if x <= target]), target, [], ans)
        return ans


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-06-11 18:26:46
# Description: 

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ret = []
        self.dfs(list(range(1, 10)), k, n, [], ret)
        return ret
    
    def dfs(self, nums, k, n, path, ret):
        if k < 0 or n < 0:
            return 
        if k == 0 and n == 0:
            ret.append(path)
        for i in range(len(nums)):
            self.dfs(nums[i+1:], k-1, n-nums[i], path+[nums[i]], ret)

if __name__ == "__main__":
   pass


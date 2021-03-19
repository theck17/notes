# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-19 19:53:53
# Description: 

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        '''
        1) conceptually contruct the brute-force tree to traverse
        2) children of the node candidates[i] are candidates[i:]
	         this is to avoid duplicates, e.g., nums[i]-->nums[i-1], nums[i-1]-->nums[i]
        '''
        def dfs(res, path, children, trgt):
            if trgt > 0:
                for i in range(len(children)):
                    dfs(res, path+[children[i],], children[i:], trgt-children[i])
            elif trgt == 0:
                res.append(path)
 
        res = []
        dfs(res, [], candidates, target)
        return res




if __name__ == "__main__":
   pass


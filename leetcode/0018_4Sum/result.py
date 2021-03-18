# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-18 21:46:48
# Description: 

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        quadruplets = set()
        hashtable = {}
        
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                currSum = nums[i] + nums[j]
                if target - currSum in hashtable:
                    for pair in hashtable[target - currSum]:
                        sortedPair = sorted([nums[i], nums[j], pair[0], pair[1]])
                        quadruplets.add(tuple(sortedPair))
                        
            for k in range(i):
                pairSum = nums[i] + nums[k]
                if pairSum not in hashtable:
                    hashtable[pairSum] = [[nums[i], nums[k]]]
                else:
                    hashtable[pairSum].append([nums[i], nums[k]])

        return quadruplets




if __name__ == "__main__":
   pass


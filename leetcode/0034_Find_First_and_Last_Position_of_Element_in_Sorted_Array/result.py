# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-22 19:53:58
# Description: 

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        finalRange = [-1, -1]
        self.binarySearchHelper(nums, target, 0, len(nums) - 1, finalRange, True)
        self.binarySearchHelper(nums, target, 0, len(nums) - 1, finalRange, False)
        return finalRange
    
    def binarySearchHelper(self, array, target, left, right, finalRange, goLeft):
        while left <= right:
            mid = (left + right) // 2
            if array[mid] < target:
                left = mid + 1
            elif array[mid] > target:
                right = mid - 1
            else:
                if goLeft:
                    if mid == 0 or array[mid - 1] != target:
                        finalRange[0] = mid
                        return
                    else:
                        right = mid - 1
                else:
                    if mid == len(array) - 1 or array[mid + 1] != taret:
                        finalRange[1] = mid
                        return
                    else:
                        left = mid + 1g




if __name__ == "__main__":
   pass


# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-10 20:33:04
# Description:


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        lis = []
        [lis.append(i) for i in nums if i > 0] # remove negative numbers
        #print(lis)
        dic = {} # use dict properties to remove duplicates
        for i in lis:
            if not dic.get(i):
                dic[i] = i
        lis = list(dic.keys())
        #print(lis)
        if not lis: #condition for empty list
            return 1
        if lis[0] > 1: # expecting best case of sorted-postive-ints-list starting with int > 1
            return 1
        for first in range(len(lis)):
            value = lis[first]
            try:
                second = lis[first + 1]
            except IndexError: # when lis[first] is last element in the list
                break
            if second - value > 1: # the condition of missing int
                return value + 1
        return value + 1 # if no missing number than last number + 1 is the output


if __name__ == "__main__":
    pass

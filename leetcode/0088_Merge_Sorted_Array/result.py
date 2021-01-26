# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-24 13:55:14
# Description:

import os, sys, re


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int],
              n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = j = k = 0
        res = [0] * len(nums1)
        while i < m and j < n:
            if nums1[i] < nums2[j]:
                res[k] = nums1[i]
                i = i + 1
                k = k + 1
            else:
                res[k] = nums2[j]
                j = j + 1
                k = k + 1
        while i < m:
            res[k] = nums1[i]
            i = i + 1
            k = k + 1
        while j < n:
            res[k] = nums2[j]
            j = j + 1
            k = k + 1
        for i in range(len(nums1)):
            nums1[i] = res[i]


if __name__ == "__main__":
    nums1 = [1, 2, 3, 0, 0, 0]
    m = 3
    nums2 = [2, 5, 6]
    n = 3
    arr = Solution(nums1, m, nums2, n)
    pass

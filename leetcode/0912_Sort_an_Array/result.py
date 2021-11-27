# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-27 19:15:37
# Description:


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def mergesort(A):
            LA = len(A)
            if LA == 1: return A
            LH, RH = mergesort(A[:LA // 2]), mergesort(A[LA // 2:])
            return merge(LH, RH)

        def merge(LH, RH):
            LLH, LRH = len(LH), len(RH)
            S, i, j = [], 0, 0
            while i < LLH and j < LRH:
                if LH[i] <= RH[j]: i, _ = i + 1, S.append(LH[i])
                else: j, _ = j + 1, S.append(RH[j])
            return S + (RH[j:] if i == LLH else LH[i:])

        return mergesort(nums)


if __name__ == "__main__":
    pass

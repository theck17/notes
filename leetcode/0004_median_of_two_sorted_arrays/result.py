# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-13 21:45:48
# Description:


class Solution:
    def findMedianSortedArrays(self, nums1: List[int],
                               nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        new_list = sorted(nums1 + nums2)
        median_index = str((m + n) / 2).split(".")
        integer = int(median_index[0])
        dec = int(median_index[1])
        if dec == 0:
            res = (new_list[integer - 1] + new_list[integer]) / 2
        else:
            res = float(new_list[integer])
        return res


if __name__ == "__main__":
    nums1 = [1, 3]
    nums2 = [2]
    a = Solution()
    res = a.findMedianSortedArrays(nums1, nums2)
    print(res)

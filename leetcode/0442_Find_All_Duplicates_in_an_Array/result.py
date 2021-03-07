# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-07 09:56:11
# Description:


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        return [num for num in cnt if cnt[num] == 2]


if __name__ == "__main__":
    pass

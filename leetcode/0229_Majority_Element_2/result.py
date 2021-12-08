# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-08 18:55:58
# Description:
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count = Counter()
        for num in nums:
            count[num] += 1
            if len(count) == 3:
                new_count = Counter()
                for elem, freq in count.items():
                    if freq != 1: new_count[elem] = freq - 1
                count = new_count

        cands = Counter(num for num in nums if num in count)
        return [num for num in cands if cands[num] > len(nums) / 3]


if __name__ == "__main__":
    pass

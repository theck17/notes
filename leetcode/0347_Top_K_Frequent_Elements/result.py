# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-19 13:32:45
# Description:
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        bucket = [[] for _ in range(len(nums) + 1)]
        Count = Counter(nums).items()
        for num, freq in Count:
            bucket[freq].append(num)
        flat_list = list(chain(*bucket))
        return flat_list[::-1][:k]


if __name__ == "__main__":
    pass

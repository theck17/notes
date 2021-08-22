# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-22 10:17:22
# Description:
from random import randint


class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums

# Time complexity: O(n), where "n" is the length of self.nums

    def pick(self, target: int) -> int:
        # how many samples with value "target" we have seen so far
        n_samples = 0

        # result, selected index
        reservoir = 0

        # iterate over all the values in self.nums
        for index, value in enumerate(self.nums):
            if value == target:
                # target value is found, increment the number of samples with value "target" found so far
                n_samples += 1

                # if it is the first sample found, just keep it index
                if n_samples == 1:
                    reservoir = index
                else:
                    # if there are more than 1 sample, randomly select any of them
                    nth_sample = randint(1, n_samples)

                    # if the selected sample matches the first sample selected initially, then replace it
                    if nh_sample == 1:
                        reservoir = index
        return reservoirt

if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-02-10 20:42:12
# Description:


class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        pair = [] ## find the two numbers and put them in pair list ##
        set_list = list(set(numbers))
        for uniq_num in set_list:
            rest = target - uniq_num
            if rest in set_list:
                pair.append([uniq_num, rest])
                break

        a = pair[0][0]
        b = pair[0][1]
        if a == b and numbers.count(a) > 1:
            i0 = numbers.index(a) + 1
            i1 = i0 + 1
        else:
            i0, i1 = numbers.index(a) + 1, numbers.index(b) + 1
        return sorted([i0, i1])


if __name__ == "__main__":
    pass

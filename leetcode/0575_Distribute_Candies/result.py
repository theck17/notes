# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-28 21:47:48
# Description:
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        d = dict()
        dict_size = 0
        for num in candyType:
            if num not in d:
                d[num] = 1
                dict_size += 1

        list_size = len(candyType) // 2

        result = list_size if list_size < dict_size else dict_size
        return result


if __name__ == "__main__":
    pass

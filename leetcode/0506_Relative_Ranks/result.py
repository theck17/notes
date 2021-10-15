# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-15 20:03:00
# Description:
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        Medal = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        size = len(score)
        res = [""] * size
        my_map = {}

        for i in range(size):
            my_map[score[i]] = i

        score.sort(reverse=True)

        for i in range(size):
            if i < 3:
                res[my_map[score[i]]] = Medal[i]
            else:
                res[my_map[score[i]]] = str(i + 1)

        return res


if __name__ == "__main__":
    pass

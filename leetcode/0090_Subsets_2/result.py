# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-05-14 22:41:03
# Description:


class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        res = [[]]
        S.sort()
        for i in range(len(S)):
            if i == 0 or S[i] != S[i - 1]:
                l = len(res)
            for j in range(len(res) - l, len(res)):
                res.append(res[j] + [S[i]])
        return res


if __name__ == "__main__":
    pass

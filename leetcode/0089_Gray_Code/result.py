# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-25 21:05:05
# Description:
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if not n:
            return [0]
        res = [0, 1]
        for i in range(2, n + 1):
            for j in range(len(res) - 1, -1, -1):
                res.append(res[j] | 1 << i - 1)
        return res


if __name__ == "__main__":
    pass

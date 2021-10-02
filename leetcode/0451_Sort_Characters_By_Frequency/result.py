# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-02 19:36:56
# Description:
class Solution:
    def frequencySort(self, s: str) -> str:
        c1, c2 = Counter(s), {}
        for k, v in c1.items():
            c2.setdefault(v, []).append(k * v)
        return "".join(
            ["".join(c2[i]) for i in range(len(s), -1, -1) if i in c2])


if __name__ == "__main__":
    pass

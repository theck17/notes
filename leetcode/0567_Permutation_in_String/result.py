# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-05 20:02:35
# Description:
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if s2 and not s1:
            return True
        s1 = "".join(sorted(list(s1)))
        k = len(s1)

        for i in range(len(s2)): # -- O(n)
            sub = s2[i:i + k] # -- O(k)
            sub_str = "".join(sorted(list(sub))) # ---- [1]

            if s1 == sub_str:
                return True
        return False


if __name__ == "__main__":
    pass

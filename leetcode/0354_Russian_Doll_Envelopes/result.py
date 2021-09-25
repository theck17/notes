# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-25 09:20:46
# Description:


class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        des_ht = [a[1] for a in sorted(envelopes, key=lambda x: (x[0], -x[1]))]
        dp, l = [0] * len(des_ht), 0
        for x in des_ht:
            i = bisect.bisect_left(dp, x, 0, l)
            dp[i] = x
            if i == l:
                l += 1
        return l


if __name__ == "__main__":
    pass

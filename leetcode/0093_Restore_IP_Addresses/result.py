# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-26 18:59:13
# Description:
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        self.helper(ans, s, 4, [])
        return ['.'.join(x) for x in ans]

    def helper(self, ans, s, k, temp):
        if len(s) > k * 3:
            return
        if k == 0:
            ans.append(temp[:])
        else:
            for i in range(min(3, len(s) - k + 1)):
                if i == 2 and int(s[:3]) > 255 or i > 0 and s[0] == '0':
                    continue
                self.helper(ans, s[i + 1:], k - 1, temp + [s[:i + 1]])



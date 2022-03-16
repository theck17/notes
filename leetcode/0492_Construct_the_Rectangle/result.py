# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-22 09:57:44
# Description:
class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        for l in range(int(area ** 0.5), 0, -1):
            if area % l == 0:
                return [area // l, l]

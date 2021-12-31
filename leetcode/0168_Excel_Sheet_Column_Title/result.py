# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-31 19:00:27
# Description:
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        ans = ""
        while columnNumber:
            columnNumber = columnNumber - 1
            ans = abc[columnNumber % 26] + ans
            columnNumber = columnNumber // 26
        return ans


if __name__ == "__main__":
    pass

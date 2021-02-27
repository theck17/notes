# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-02-04 21:51:27
# Description:

import os, sys


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cash, hold = 0, -prices[0]
        for i in range(len(prices)):
            cash = max(cash, hold + prices[i])
            hold = max(hold, cash - prices[i])
        return cash

    def maxProfit(self, prices: List[int]) -> int:
        ans, n = 0, len(prices)
        for i in range(1, n):
            ans += max(0, prices[i] - prices[i - 1])
        return ans


if __name__ == "__main__":
    pass

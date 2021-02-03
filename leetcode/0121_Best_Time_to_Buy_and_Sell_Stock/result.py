# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-02-03 19:15:27
# Description:


class Solution:
    def maxProfit(self, prices) -> int:
        maxprofit = 0
        minprice = prices[0]
        for i in range(len(prices)):
            if (prices[i] < minprice):
                minprice = prices[i]
            if ((prices[i] - minprice) > maxprofit):
                maxprofit = prices[i] - minprice
        return maxprofit


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-02-07 22:23:30
# Description:


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        FORWARDS, BACKWARDS = 1, -1

        def findBestDeal(
            start, end, direction
        ): # this is just the solution to the easier version of the question with only 1 transaction
            lowestCost = (inf, 0) # (lowestCost, indexOfLowestCost)
            profit = (0, 0, 0) # (maxProfit, indexOfBuy, indexOfSell)
            for i in range(start, end, direction):
                price = prices[i]
                lowestCost = min(lowestCost, (price, i))
                profit = max(profit, (price - lowestCost[0], lowestCost[1], i))
            return profit # return (profit, buyindex, sellindex)

        profit, firstBuy, firstSell = findBestDeal(0, len(prices), FORWARDS)

        bestBefore = findBestDeal(0, firstBuy, FORWARDS)[0]
        bestAfter = findBestDeal(firstSell + 1, len(prices), FORWARDS)[0]

        # the way that we find the biggest drop in price over buy:sell is actually by reversing
        #    the array and finding the biggest increase in the reversed array
        biggestDip = findBestDeal(firstSell, firstBuy - 1, BACKWARDS)[0]

        profit += max(bestBfore, bestAfter, biggestDip)
        return profite


if __name__ == "__main__":
    pass

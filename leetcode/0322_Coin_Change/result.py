# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-07 14:32:50
# Description:
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[math.inf] * (amount + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = 0

        for i in range(1, n + 1):
            for amnt in range(1, amount + 1):
                dp[i][amnt] = dp[i - 1][amnt] # Skip ith coin
                if amnt >= coins[i - 1]:
                    dp[i][amnt] = min(dp[i][amnt], dp[i][amnt - coins[i - 1]] +
                                      1) # Take ith coin

        return dp[n][amount] if dp[n][amount] != math.inf else -1


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-15 20:08:28
# Description:
class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        N = len(matchsticks)
        basket, rem = divmod(sum(matchsticks), 4)
        if rem or max(matchsticks) > basket: return False

        @lru_cache(None)
        def dfs(mask):
            if mask == 0: return 0
            for j in range(N):
                if mask & 1 << j:
                    neib = dfs(mask ^ 1 << j)
                    if neib >= 0 and neib + matchsticks[j] <= basket:
                        return (neib + matchsticks[j]) % basket
            return -1

        return dfs((1 << N) - 1) == 0


if __name__ == "__main__":
    pass

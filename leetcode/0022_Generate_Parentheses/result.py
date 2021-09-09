# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-09 21:27:44
# Description:


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def dfs(l, r, path, res):
            if r < l or l == -1 or r == -1:
                return
            if l == 0 and r == 0:
                res.append(path[:])
            else:
                dfs(l - 1, r, path + "(", res)
                dfs(l, r - 1, path + ")", res)

        dfs(n, n, "", res)
        return (res)


if __name__ == "__main__":
    pass

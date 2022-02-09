# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-09 09:48:27
# Description:
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return moves.count('L') == moves.count('R') and moves.count(
            'U') == moves.count('D')


if __name__ == "__main__":
    pass

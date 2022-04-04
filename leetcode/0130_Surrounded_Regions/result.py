# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-09 17:26:27
# Description: 
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return
        R, C = len(board), len(board[0])
        if R<=2 or C<=2:
            return
        queue = collections.deque()
        for r in range(R):
            queue.append((r, 0))
            queue.append((r, C - 1))

        for c in range(len(board[0])):
            queue.append((0, c))
            queue.append((R - 1, c))

        while queue:
            r, c = queue.popleft()
            print(r, c)
            if 0 <= r < R and 0 <= c < C and board[r][c] == 'O':
                board[r][c] = 'N'
                queue.append((r-1, c))
                queue.append((r + 1, c))
                queue.append((r, c + 1))
                queue.append((r, c - 1))

        for r in range(R):
            for c in range(C):
                if board[r][c] == 'N':
                    board[r][c] = 'O'
               else:
                    board[r][c] = 'X' 


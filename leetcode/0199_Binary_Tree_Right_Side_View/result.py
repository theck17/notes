# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-04 21:46:20
# Description:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        deque = collections.deque()
        if root:
            deque.append(root)
        res = []
        while deque:
            size, val = len(deque), 0
            for _ in range(size):
                node = deque.popleft()
                val = node.val # store last value in each level
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(val)
        return res

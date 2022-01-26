# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-26 19:47:49
# Description:


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root: return None
        root.left, root.right = self.invertTree(root.right), self.invertTree(
            root.left)

        return root


if __name__ == "__main__":
    pass

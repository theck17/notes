# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-07 08:41:14
# Description:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        if not root1 and not root2: return None
        res = TreeNode((root1.val if root1 else 0) +
                       (root2.val if root2 else 0))
        res.left = self.mergeTrees(root1 and root1.left, root2 and root2.left)
        res.right = self.mergeTrees(root1 and root1.right, root2
                                    and root2.right)
        return res

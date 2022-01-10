# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-10 18:38:06
# Description:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        queue = [(root, targetSum - root.val)]
        while queue:
            curr, val = queue.pop(0)
            if not curr.left and not curr.right and val == 0:
                return True
            if curr.left:
                queue.append((curr.left, val - curr.left.val))
            if curr.right:
                queue.append((curr.right, val - curr.right.val))
        return False


if __name__ == "__main__":
    pass

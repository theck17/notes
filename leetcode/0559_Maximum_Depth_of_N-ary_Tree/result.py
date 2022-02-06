# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-06 10:07:50
# Description:
"""
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root == None:
            return 0
        depth = 0

        for child in root.children:
            depth = max(depth, self.maxDepth(child))

        print('root ' + str(root.val) + ' depth ' + str(depth + 1))
        return depth + 1


if __name__ == "__main__":
    pass

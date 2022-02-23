# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-23 10:15:14
# Description:
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        ret, q = [], root and [root]
        while q:
            node = q.pop()
            ret.append(node.val)
            q += [child for child in node.children[::-1] if child]
        return ret


if __name__ == "__main__":
    pass

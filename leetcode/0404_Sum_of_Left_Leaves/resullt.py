# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-24 21:40:34
# Description:
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        result = 0
        stack = [(root, False)]
        while stack:
            curr, is_left = stack.pop()
            if not curr:
                continue
            if not curr.left and not curr.right:
                if is_left:
                    result += curr.val
            else:
                stack.append((curr.left, True))
                stack.append((curr.right, False))
        return result


if __name__ == "__main__":
    pass

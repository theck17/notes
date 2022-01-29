# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-29 23:15:20
# Description:
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        return self.diameter_rec(root)[0]

    def diameter_rec(self, root):
        if not root:
            return 0, -1

        left_diameter, left_height = self.diameter_rec(root.left)
        right_diameter, right_height = self.diameter_rec(root.right)
        return (max(left_diameter, right_diameter,
                    left_height + right_height + 2),
                max(left_height, right_height) + 1)


if __name__ == "__main__":
    pass

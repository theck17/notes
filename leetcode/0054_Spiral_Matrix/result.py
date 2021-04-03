# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-04-03 11:19:24
# Description:


class Solution:
    # Time complexity - O(N*M)
    # Space complexity - O(1)
    # Approach - optimal - 4 pointer approach
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        row_size = len(matrix)
        col_size = len(matrix[0])
        top = 0
        bottom = row_size - 1
        left = 0
        right = col_size - 1
        direction = 0
        final_list = []
        while (top <= bottom and left <= right):
            print(top, bottom, left, right, direction)
            if (direction == 0):
                for i in range(left, right + 1):
                    final_list.append(matrix[top][i])
                top += 1

            elif (direction == 1):
                for i in range(top, bottom + 1):
                    final_list.append(matrix[i][right])
                right -= 1

            elif (direction == 2):
                for i in range(right, left - 1, -1):
                    final_list.append(matrix[bottom][i])
                bottom -= 1

            elif (direction == 3):
                for i in range(bottom, top - 1, -1):
                    final_list.append(matrix[i][left])
                left += 1

            direction = (direction + 1) % 4

        return final_list


if __name__ == "__main__":
    pass

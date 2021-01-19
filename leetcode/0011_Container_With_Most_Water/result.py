# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-01-19 21:46:11
# Description:


class Solution:
    def maxArea(self, height: List[int]) -> int:
        if not height:
            return
        i = 0
        j = len(height) - 1
        maxarea = 0
        while (i != j):
            minheight = min(height[i], height[j])
            area = (j - i) * minheight
            if area > maxarea:
                maxarea = area
            if minheight == height[i]:
                i += 1
            else:
                j -= 1
        return maxarea


if __name__ == "__main__":
    pass

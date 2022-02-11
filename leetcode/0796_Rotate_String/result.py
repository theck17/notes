# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-02-11 12:34:44
# Description:
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal): return False
        if len(s) == 0: return True

        N = len(s)
        A = " " + s + s
        B = " " + goal

        pi = [0] * (N + 1)
        left, pi[0] = -1, -1
        for right in range(1, N + 1):
            while left >= 0 and B[left + 1] != B[right]:
                left = pi[left]
            left += 1
            pi[right] = left

        j = 0
        for i in range(1, (2 * N) + 1):
            while j >= 0 and B[j + 1] != A[i]:
                j = pi[j]
            j += 1
            if j == N: return True

        return False


if __name__ == "__main__":
    pass

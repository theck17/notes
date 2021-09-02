# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-02 21:50:36
# Description:
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        # The main idea is to understand that cow cases contain the bull cases
        # This loop will take care of "bull" cases
        bull = 0
        for i in range(len(secret)):
            bull += int(secret[i] == guess[i])

# This loop will take care of "cow" cases
        cows = 0
        for c in set(secret):
            cows += min(secret.count(c), guess.count(c))

        return f"{bull}A{cows-bull}B"

if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-17 19:08:04
# Description:
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []
        for h in range(0, 12):
            for m in range(0, 60):
                if self.bitcount(h) + self.bitcount(m) == turnedOn:
                    time = str(h) + ":"
                    if m < 10:
                        time += "0" + str(m)
                    else:
                        time += str(m)
                    ans.append(time)
        return ans

    # count how many bit will represent the number i.e. 15 is 1011 count will be 4
    def bitcount(self, n):
        count = 0
        while n > 0:
            if (n & 1 == 1):
                count += 1
            n >>= 1
        return count


if __name__ == "__main__":
    pass

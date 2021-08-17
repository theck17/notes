# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-17 22:06:50
# Description:
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        # set for sequence
        sequence = set()

        # set for sequence with repetition
        repeated = set()

        for i in range(len(s) - 9):

            # make current sequence for i to i+10
            cur_seq = s[i:i + 10]

            if cur_seq in sequence:
                # check for repetition
                repeated.add(cur_seq)

            # add to sequence set
            sequence.add(cur_seq)

        return [*repeated]


if __name__ == "__main__":
    pass

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-21 22:39:38
# Description:
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        words1 = {word: idx for idx, word in enumerate(list1)}

        min_sum = math.inf
        for idx2, word2 in enumerate(list2):
            if word2 in words1:
                if words1[word2] + idx2 < min_sum:
                    min_sum = words1[word2] + idx2
                    min_words = [word2]
                elif words1[word2] + idx2 == min_sum:
                    min_words.append(word2)

        return min_words


if __name__ == "__main__":
    pass

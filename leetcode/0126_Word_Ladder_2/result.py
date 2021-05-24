# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-05-24 18:24:44
# Description:

import os
import sys


class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):

        wordList = set(wordList)
        res = []
        layer = {}
        layer[beginWord] = [[beginWord]]

        while layer:
            newlayer = collections.defaultdict(list)
            for w in layer:
                if w == endWord:
                    res.extend(k for k in layer[w])
                else:
                    for i in range(len(w)):
                        for c in 'abcdefghijklmnopqrstuvwxyz':
                            neww = w[:i] + c + w[i + 1:]
                            if neww in wordList:
                                newlayer[neww] += [
                                    j + [neww] for j in layer[w]
                                ]

            wordList -= set(newlayer.keys())
            layer = newlayer

        return res


if __name__ == "__main__":
    pass

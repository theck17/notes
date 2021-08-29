# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-29 12:46:44
# Description:
class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        rootset = set(dictionary)

        def replace(word):
            for i in range(1, len(word)):
                if word[:i] in rootset:
                    return word[:i]
            return word

        return " ".join(map(replace, sentence.split()))

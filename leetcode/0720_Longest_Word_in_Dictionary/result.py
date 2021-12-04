# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-04 09:48:17
# Description: 
class Solution:
    def longestWord(self, words: List[str]) -> str:
        valid = set([""])
       
        for word in sorted(words, key=lambda x: len(x)):
           if word[:-1] in valid:
                valid.add(word)
								
        return max(sorted(valid), key=lambda x: len(x))

if __name__ == "__main__":
   pass


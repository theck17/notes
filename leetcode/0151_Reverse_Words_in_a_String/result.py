# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-12 11:58:12
# Description:
class Solution:
    def reverseWords(self, s: str) -> str:
        word = ""
        words = ""
        s = s[::-1]
        for j, i in enumerate(s):
            if i != " " and word != "" and s[j - 1] == " ":
                words += (word + " ")
                word = i
            elif i != " ":
                word = i + word
            else:
                continue
        words += word
        return (words)


if __name__ == "__main__":
    pass

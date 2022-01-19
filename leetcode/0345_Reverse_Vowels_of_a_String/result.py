# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-19 18:49:06
# Description:
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set(list("aeiouAEIOU"))
        s = list(s)
        ptr_1, ptr_2 = 0, len(s) - 1
        while ptr_1 < ptr_2:
            if s[ptr_1] in vowels and s[ptr_2] in vowels:
                s[ptr_1], s[ptr_2] = s[ptr_2], s[ptr_1]
                ptr_1 += 1
                ptr_2 -= 1
            if s[ptr_1] not in vowels:
                ptr_1 += 1
            if s[ptr_2] not in vowels:
                ptr_2 -= 1
        return ''.join(s)


if __name__ == "__main__":
    pass

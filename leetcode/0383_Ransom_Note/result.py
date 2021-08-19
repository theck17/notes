# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-19 23:00:12
# Description:
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for c in set(ransomNote):
            if magazine.count(c) < ransomNote.count(c):
                return False
        return True


if __name__ == "__main__":
    pass

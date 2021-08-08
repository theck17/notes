# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-08-08 18:15:05
# Description:
class Solution:
    def simplifyPath(self, path: str) -> str:
        places = [p for p in path.split("/") if p != "." and p != ""]
        stack = []
        for p in places:
            if p == "..":
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(p)
        return "/" + "/".join(stack)


if __name__ == "__main__":
    pass

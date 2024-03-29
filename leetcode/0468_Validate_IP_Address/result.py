# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-11-03 19:43:04
# Description:
class Solution:
    def validIPAddress(self, IP: str) -> str:
        if "." in IP:
            splitted = IP.split(".")
            if len(splitted) != 4: return "Neither"
            for part in splitted:
                if len(part) == 0 or (len(part) > 1 and part[0] == "0"):
                    return "Neither"
                if not part.isnumeric() or int(part) > 255: return "Neither"
            return "IPv4"
        elif ":" in IP:
            symbols = "0123456789abcdefABCDEF"
            splitted = IP.split(":")
            if len(splitted) != 8: return "Neither"
            for part in splitted:
                if len(part) == 0 or len(part) > 4: return "Neither"
                for elem in part:
                    if elem not in symbols: return "Neither"
            return "IPv6"
        return "Neither"


if __name__ == "__main__":
    pass

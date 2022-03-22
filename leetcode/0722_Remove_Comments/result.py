# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-24 18:49:45
# Description:
class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        s = '\n'.join(source)
        regex_single = r"\/\/.*"
        regex_block_closed = r"(?s:\/\*.*?\*\/)"
        regex_block_not_closed = r"\/\*.*"
        regex = '|'.join(
            [regex_single, regex_block_closed,
             regex_block_not_closed]) # order matters
        s = re.sub(regex, '', s)
        return list(filter(None, s.split('\n')))

# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2022-01-16 13:20:06
# Description:
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None

        while head:
            next_node = head.next
            head.next = prev
            prev = head
            head = next_node

        return prev


if __name__ == "__main__":
    pass

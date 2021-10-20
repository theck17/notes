# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-20 22:03:53
# Description:
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = cur = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 or l2
        return dummy.next


if __name__ == "__main__":
    pass

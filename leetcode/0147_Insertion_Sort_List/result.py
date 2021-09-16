# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-09-16 21:26:00
# Description:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        dummyHead = ListNode(0)

        def insert(head):
            prev = dummyHead
            curr = dummyHead.next
            while curr and curr.val <= head.val:
                prev = curr
                curr = curr.next

            prev.next = head
            head.next = curr

        while head != None:
            next = head.next
            insert(head)
            head = next

        return dummyHead.next


if __name__ == "__main__":
    pass

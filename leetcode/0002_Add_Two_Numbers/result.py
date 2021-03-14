# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-03-14 09:40:13
# Description:


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = self.getNumber(l1)
        num2 = self.getNumber(l2)
        # get the sum
        num = num1 + num2
        # change num to string
        num = str(num)
        # initialize
        res = None
        for char in num:
            res = ListNode(val=int(char), next=res)
        return res

    def getNumber(self, l: ListNode):
        """
        return the number from the ListNode
            if l=[2,4,3], the number is 342
        """
        num = ""
        prev = None

        while l:
            num += str(l.val)
            next = l.next
            l.next = prev
            prev = l
            l = next

        return int(num[::-1])


if __name__ == "__main__":
    pass

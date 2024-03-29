# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-10-26 20:46:59
# Description:
class Solution:
    def rotateRight(self, head: Optional[ListNode],
                    k: int) -> Optional[ListNode]:
        if not head:
            return None
        lastElement = head
        length = 1
        while (lastElement.next):
            lastElement = lastElement.next
            length += 1
        k = k % length
        lastElement.next = head
        tempNode = head
        for _ in range(length - k - 1):
            tempNode = tempNode.next
        answer = tempNode.next
        tempNode.next = None
        return answer


if __name__ == "__main__":
    pass

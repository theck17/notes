/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-05 19:01:16
 *   Description   ：
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if (headA == NULL || headB == NULL)
        return NULL;
    int sizeA = 0, sizeB = 0;
    struct ListNode *currA = headA;
    struct ListNode *currB = headB;
    
    while (currA) {
        sizeA++;
        currA = currA->next;
    }
    while(currB) {
        sizeB++;
        currB = currB->next;
    }
    
    currA = headA;
    currB = headB;
   int diff = sizeA - sizeB;
    
    if (sizeA < sizeB) {
        for (int i = diff; i < 0; i++)
            currB = currB->next;
    } else {
        for (int i = diff; i > 0; i--)
            currA = currA->next;
    }
    /* find the intersection node */
    while (currA) {
        if (currA == currB)
            return currA;
        currA = currA->next;
        currB = currB->next;
    }
    return NULL;
}

int main(){
    return 0;
}

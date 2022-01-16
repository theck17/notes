/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-16 13:19:03
 *   Description   ：
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *current = head; // Current pointer
    struct ListNode *prev = NULL;    // pointer to prev node
    struct ListNode *next = NULL;    // pointer to next node

    // Traverse and make the pointer adjustments
    while(current!=NULL) {
        next = current->next; // Store next node so that it won't be lost during this reversal
        current->next = prev; // Reverse the required pointers
        prev = current; // Move through the list
        current = next;
    }

    // Once reversal is done, return modified head
    head = prev;
    return head;
}

int main(){
    return 0;
}

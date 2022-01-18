/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-18 21:36:40
 *   Description   ：
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* temp;
    temp=node->next;
    node->val=temp->val;
    node->next=temp->next;
    free(temp);
}
int main(){
    return 0;
}

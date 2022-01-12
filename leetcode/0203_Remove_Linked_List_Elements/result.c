/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-12 20:18:47
 *   Description   ：
 */
struct ListNode* removeElements(struct ListNode* head, int val){
        if(head==NULL){
        return head;
    }
    struct ListNode *current=head;

    while(current->next!=NULL){
        if(current->next->val==val){
            current->next=current->next->next;
        }
        else{
            current=current->next;
        }
    }
    if(head->val==val){
        head=head->next;
    }
    return head;
}

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-26 20:45:44
 *   Description   ：
 */
using namespace std;
class Solution {
public:
     ListNode *rotateRight(ListNode *head, int k) 
     {
        if(head == NULL || head->next == NULL||k==0) return head;
        ListNode* node = head;
        int size =1;
        while(node->next != NULL)
        {
            size++;
            node = node->next;
        }
        //loop the list
        node->next=head;
        //handle the case of k>size
        k = k%size;
        //find the node to break the loop at
        while(--size >= k)
        {
            node=node->next;
        }
        ListNode* first = node->next;
        node->next=NULL;
        return first;
    }
};

int main(){
    return 0;
}

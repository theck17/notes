/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-05 09:59:56
 *   Description   ：
 */
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* newHead, *copyNode, *temp= head;
        
        //step 1. create copy node in between original node which helps to connect random node of copy node.
        while(temp)
        {
            copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
        //result - 7 -> 7 -> 13 -> 13 -> 11 -> 11 -> 10 -> 10 -> 1 -> 1 -> NULL
        
        newHead = head->next;
        temp = head;
        
        //step 2. now copyNode->random lie just after original->randomNode.
        while(temp)
        {
            if(temp->random == NULL)
                temp->next->random = NULL;
            
            else 
               temp->next->random = temp->random->next;
            
            temp = temp->next->next;
        }
        //result-  Nodes copied successfully. Now we just need to seprate them.
        temp = head;
        
        //step 3. separating copy Node from original Nodes
        while(temp)
        {
            copyNode = temp->next;
            temp->next = copyNode->next;
            
            if(copyNode->next)
                copyNode->next = copyNode->next->next;
            
            temp = temp->next;
        }
        
        return newHead;
    }
}; 


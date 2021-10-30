/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-30 10:37:32
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
    	return sortedListToBST( head, NULL );
    }
    
private:
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
    	if( head == tail )
    		return NULL;
    	if( head->next == tail )    // 
    	{	
    		TreeNode *root = new TreeNode( head->val );
    		return root;
    	}
    	ListNode *mid = head, *temp = head;
    	while( temp != tail && temp->next != tail )    // 寻找中间节点
    	{
    		mid = mid->next;
    		temp = temp->next->next;
    	}
    	TreeNode *root = new TreeNode( mid->val );
    	root->left = sortedListToBST( head, mid );
    	root->right = sortedListToBST( mid->next, tail );
    	return root;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-12 12:13:43
 *   Description   ：
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int tree_tilt = 0;
int node_sum(struct TreeNode *root)
{
	int node_tilt,left_sum = 0, right_sum = 0;
	if (root != NULL)
	{
		left_sum = node_sum(root->left);
		right_sum = node_sum(root->right);
		node_tilt = abs(left_sum - right_sum);
		tree_tilt+=node_tilt;
		return(root->val + left_sum + right_sum);
	}
	else
		return(0);
}
int findTilt(struct TreeNode* root)
{
    tree_tilt=0;
	node_sum(root);
	return(tree_tilt);
}

int main(){
    return 0;
}

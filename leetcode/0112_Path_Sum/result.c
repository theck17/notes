/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-10 18:37:19
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


bool count(struct TreeNode *root,int sum)
{
    if(root==NULL) return false;
    sum-=root->val;
    if(sum==0&&root->left==NULL&&root->right==NULL)
        return true;
    return (count(root->left,sum)||count(root->right,sum));
}

bool hasPathSum(struct TreeNode* root, int sum){
    if (root==NULL) 
        return false;
    return count(root,sum);
}

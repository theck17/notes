/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-27 18:38:15
 *   Description   ：
 */
#include <stdlib.h>      //动态分配函数和随机函数 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void flatten(struct TreeNode* root)
{
        if(root)
        {
            struct TreeNode* flat_tree = root->right;
            
            flatten(root->left);
            flatten(root->right);
            
            root->right = root->left;
            root->left = NULL;
            while(root->right)
            {
                root = root->right;
            }
            
            root->right = flat_tree;
        }
   
}

int main(){
    return 0;
}

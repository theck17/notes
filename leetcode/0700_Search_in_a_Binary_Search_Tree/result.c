/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-28 11:14:33
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


struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode *p = root;
    while (p != NULL && p->val != val) {
        if (p->val > val) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return p;
}

int main(){
    return 0;
}

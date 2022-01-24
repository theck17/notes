/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：resullt.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-24 21:39:05
 *   Description   ：
 */
bool isleaf(struct TreeNode *root) {
    return root->left == NULL && root->right == NULL;
}

int sumOfLeftLeaves(struct TreeNode* root){
    if (root == NULL)
        return 0;
    if (root->left) {
        if(isleaf(root->left))
            return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

}

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-01 19:09:40
 *   Description   ：
 */
int nodeCount(struct TreeNode* root) {
    if (NULL == root)
        return 0;
    
    return (nodeCount(root->left)+ nodeCount(root->right)) + 1;
}

void preorder(struct TreeNode* root, int *res, int *size) {
    if(NULL == root)
        return;
    
    res[(*size)++] = root->val;
    preorder(root->left, res, size);
    preorder(root->right, res, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int lev = nodeCount(root);
    
    int *result =(int*)malloc(sizeof(int)*lev+1);
    *returnSize = 0;

    preorder(root, result, returnSize);
    
    return result;
}

int main(){
    return 0;
}

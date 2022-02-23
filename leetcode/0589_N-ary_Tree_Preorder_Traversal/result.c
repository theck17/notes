/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-23 10:14:36
 *   Description   ：
 */
/**
 * 
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int idx;

void dfs(struct Node* root, int *A){
    if(!root) return;
    A[idx++]=root->val;
    for(int i=0; i<root->numChildren; i++)
        dfs(root->children[i], A);
}
int* preorder(struct Node* root, int* returnSize) {
    int *A = (int*)malloc(10000*sizeof(int));
    idx=0;
    dfs(root, A);
    *returnSize = idx;
    return A;
}

int main(){
    return 0;
}

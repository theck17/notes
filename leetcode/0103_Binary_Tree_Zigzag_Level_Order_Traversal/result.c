/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-07 19:01:20
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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct TreeQueue {
    struct TreeNode * node;
    struct TreeQueue * next;
    int level;
};

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL){
        *returnSize = 0;
        return NULL;
    }
    struct TreeQueue * start, *end;
    struct TreeQueue * node = malloc(sizeof(struct TreeQueue));
    node->node = root;
    node->next = NULL;
    node->level = 0;
    start = node;
    end = node;
    
    int next_level = 1;
    int ** result = malloc(sizeof(int *) * 1000);
    int i = 0;
    int cur_num, this_level;
    struct TreeQueue * l, * r;
    int j, num;
    int ave;
    
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    
    while (1){
        (*returnColumnSizes)[*returnSize] = next_level;
        *returnSize = *returnSize + 1;
        cur_num = next_level;
        next_level = 0;
        int save;
        this_level = start->level;
        result[this_level] = malloc(sizeof(int) * cur_num);
        for (i = 0; i < cur_num; i++){
            result[this_level][i] = start->node->val;
            if (start->node->left != NULL){
                l = malloc(sizeof(struct TreeQueue));
                l->node = start->node->left;
                l->next = NULL;
                l->level = start->level + 1;
                next_level++;
                end->next = l;
                end = end->next;
            }
            if (start->node->right != NULL){
                r = malloc(sizeof(struct TreeQueue));
                r->node = start->node->right;
                r->next = NULL;
                r->level = start->level + 1;
                next_level++;
                end->next = r;
                end = end->next;
            }
            start = start->next;
            //free(start);
        }
        if (next_level == 0)
            break;
    }
    for (i = 1; i < *returnSize; i+=2){
        num = returnColumnSizes[0][i];
        for (j = 0; j < (returnColumnSizes[0][i] + 1) / 2; j++){
            save = result[i][j];
            result[i][j] = result[i][num - 1 - j];
            result[i][num - 1 - j] = save;
        }
    }
    return result;
}s

int main(){
    return 0;
}

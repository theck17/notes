/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-06 10:05:41
 *   Description   ：
 */

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int maxDepth(struct Node* root) {
    int i;
    int this_max;
    int local_max=0;
    if (root==NULL) return 0;
    for (i=0; i<root->numChildren; i++) {
        this_max = maxDepth(root->children[i]);
        if (this_max > local_max) local_max = this_max;
    }
    return 1 + local_max;
}

int main(){
    return 0;
}

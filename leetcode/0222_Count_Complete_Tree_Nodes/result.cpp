/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-23 11:20:23
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int countNodes(int l_level,TreeNode* root)
    {
        if(!root) return 0;
        TreeNode* r=root->right;
        int r_level=0;
        while(r) {r_level++;r=r->left;}
        if(l_level==r_level) return (1<<l_level)+countNodes(l_level-1,root->right);
        return countNodes(l_level-1,root->left)+(1<<r_level);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* l=root->left,*r=root->right;
        int l_level=0,r_level=0;
        while(l) {l_level++;l=l->left;}
        while(r) {r_level++;r=r->left;}
        if(l_level==r_level) return (1<<l_level)+countNodes(l_level-1,root->right);
        return (1<<r_level)+countNodes(l_level-1,root->left);
    }
};

int main(){
    return 0;
}

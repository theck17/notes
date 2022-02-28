/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-28 10:57:26
 *   Description   ：
 */
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        TreeNode *node=new TreeNode(); 
        if(val<root->val){
            node=searchBST(root->left,val);
        } else if(val>root->val){
            node=searchBST(root->right,val);
        } else {
            node=root;
        }
        return node;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：resullt.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-24 21:37:52
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
        if (!root) return 0;
        if (!root->left && !root->right) return isleft ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};

int main(){
    return 0;
}

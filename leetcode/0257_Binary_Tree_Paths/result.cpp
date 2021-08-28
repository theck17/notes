/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-28 10:10:06
 *   Description   ：
 */
#include <ctime>           //定义关于时间的函数
using namespace std;
class Solution {
public:
    void helper(TreeNode* root,vector<string>& answer,string curr){
        if(!root)return;
        if(root->left||root->right)curr+=(to_string(root->val)+"->");
        else{
            curr+=(to_string(root->val));
            answer.push_back(curr);
        }
        helper(root->left,answer,curr);
        helper(root->right,answer,curr);  
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string curr="";
        helper(root,answer,curr);
        return answer;
    }
};

int main(){
    return 0;
}

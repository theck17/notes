/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-23 10:11:31
 *   Description   ：
 */
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void travel(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        result.push_back(root -> val);
        for (Node* child : root -> children) {
            travel(child, result);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        travel(root, result);
        return result;
    }
};

int main(){
    return 0;
}

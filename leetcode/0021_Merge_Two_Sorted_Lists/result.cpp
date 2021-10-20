/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-20 21:17:42
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a || b && a->val > b->val) swap(a, b);
        if (a) a->next = mergeTwoLists(a->next, b);
        return a;
    }
};

int main(){
    return 0;
}

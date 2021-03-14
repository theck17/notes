/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-14 09:36:23
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int v1=0;
        int v2 =0;
        int carry=0;
        
        ListNode* current= new ListNode(0);
        ListNode * ans= current;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            
            if(l1!=nullptr){
                v1=l1->val;
                l1=l1->next;
            }else{
                v1=0;
            }
            
            if(l2!=nullptr){
                v2=l2->val;
                l2=l2->next;
            }else{
                v2=0;
            }
            
            carry+=(v1+v2);
            
            current->next= new ListNode (carry%10);
            current=current->next;
            cary/=10;
            
        }
        return ans->next;
    }
};

    r



int main(){
    return 0;
}

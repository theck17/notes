/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-24 21:19:31
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <string>          //字符串类
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& a, int v) {
        int n = a.size();
        int vn=0, vf=-1;
        //count elements with value k
        for(int i=0;i<n;i++){
            if(a[i] == v){
                vn++;
                if(vf == -1)    vf = i; // store the first occurence of the v value
            }
        }

        if(vn == 0) return n;

        //(n - no. of occurence of v) will be the size of new array,

        for(int i=n-vn; i< n;i++){
            //so start swapping the unique elements of the array from (n-vn)th index (0 indexed) with the indicies with value v in the (v-vn) sized array partition
            if(a[i] != v){
                a[vf] = a[i];
                while(vf+1 < n && vf+1 < i && a[++vf] != v){} //increment vf to the next occurenece of v such that it do not surpass the whole array and it woll be less than the current iterated ith index
            }
        }

        return n-vn;
    }
};

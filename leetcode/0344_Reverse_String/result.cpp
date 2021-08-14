/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-14 23:43:28
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size() - 1;    
        revStr(s, start, end);
    }
    
    void revStr(vector<char>& s, int start, int end){
        if(start >= end) return;
        int temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        
        revStr(s, start+1, end-1);
    }
};

int main(){
    return 0;
}

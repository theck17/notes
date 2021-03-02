/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-21 21:31:37
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int s = digits.size()-1;
        while(s>-1){
            if(digits[s]+1==10){
                digits[s]=0;
            }else{
                digits[s]+=1;
                return digits;
            }
            s--;
        }
        vector<int> ans(digits.size()+1,0);
        ans[0]=1;
        return ans;
    }
};

int main(){
    return 0;
}

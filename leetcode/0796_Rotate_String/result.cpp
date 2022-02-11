/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-11 12:31:55
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return 0;
        s+=s;
        if(s.find(goal)!=string::npos) 
            return true;
        return false;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-06 16:37:45
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        while (isalnum(s[i]) == false && i < j) i++;
        while (isalnum(s[j]) == false && i < j) j--;
        if (toupper(s[i]) != toupper(s[j])) return false;
    }
    
    return true;
}
};

int main(){
    return 0;
}

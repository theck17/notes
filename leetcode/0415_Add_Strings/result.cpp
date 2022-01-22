/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-22 16:39:01
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i1 = num1.size() - 1, i2 = num2.size() - 1, carry = 0;
        while (i1 >= 0 || i2 >= 0 || carry > 0) {
            if (i1 >= 0) {
                carry += num1[i1] - '0';
                i1 -= 1;
            }
            if (i2 >= 0) {
                carry += num2[i2] - '0';
                i2 -= 1;
            }
            ans += char(carry % 10 + '0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    return 0;
}

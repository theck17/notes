/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-27 21:33:00
 *   Description   ：
 */
#include <ctime>           //定义关于时间的函数
using namespace std;
class Solution {
public:
    int calculate(string s) {
        int total = 0;
        vector<int> signs(2, 1);
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (c >= '0') {
                int number = 0;
                while (i < s.size()  &&  s[i] >= '0')
                    number = 10 * number + s[i++] - '0';
                total += signs.back() * number;
                signs.pop_back();
                i--;
            }
            else if (c == ')')
                signs.pop_back();
            else if (c != ' ')
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
        }
        return total;
    }
};

int main(){
    return 0;
}

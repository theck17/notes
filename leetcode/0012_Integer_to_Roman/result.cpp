/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-09 19:43:58
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    string intToRoman(int num) 
    {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int i=0; num != 0; i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += sym[i];
            }
        }
        
        return res;
    }
};

int main(){
    return 0;
}

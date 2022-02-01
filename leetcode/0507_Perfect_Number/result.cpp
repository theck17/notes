/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-01 14:20:03
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if ((num == 1) || (num < 0)) // edge cases - number is negitive or 1
            return false;
        
        int i = 2;
        int res = 1;
        for (; i<sqrt(num); i++)
        {
            if (num % i == 0)
                res += i + num/i;
        }
        
        if ((int(sqrt(num)) >= i ) && (num % i == 0)) // edge case - number has a whole sqrt
            res += i;
        
        return res == num;
    }
};

int main(){
    return 0;
}

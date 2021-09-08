/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-08 19:14:54
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> tmp;
        
        while(n != 1)
        {
            if(tmp.find(n) == tmp.end())
                tmp.insert(n);
            else
                return false;
            
            int sum = 0;
            while(n != 0)
            {
                sum += pow(n % 10,2);
                n = n / 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};

int main(){
    return 0;
}

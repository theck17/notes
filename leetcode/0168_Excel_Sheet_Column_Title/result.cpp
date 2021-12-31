/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-31 18:58:36
 *   Description   ：
 */
using namespace std;
class Solution {

public:

string convertToTitle(int n) {

    string res;

    char tmp;

    while(n){

        n -= 1;

        tmp = 'A' + n % 26;

        res = tmp + res;

        n /= 26;

    }

    return res;

}
};

int main(){
    return 0;
}

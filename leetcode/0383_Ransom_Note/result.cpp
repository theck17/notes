/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-19 22:56:46
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <ctime>           //定义关于时间的函数
using namespace std;
class Solution {
public:
    bool canConstruct( string ransomNote, string magazine ) {
        unordered_map<char, int> magazineLetterFreq;
        for( auto c : magazine )  magazineLetterFreq[c]++;
        for( auto c : ransomNote )  if( --magazineLetterFreq[c] < 0 ) return false;
        return true;
    }
};

int main(){
    return 0;
}

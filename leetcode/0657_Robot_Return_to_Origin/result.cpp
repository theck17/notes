/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-09 09:41:20
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> c;
        for ( char m : moves )
            ++c[m];
        return c['L'] == c['R'] && c['U'] == c['D'];
    }
};

int main(){
    return 0;
}

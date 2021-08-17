/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-17 22:05:44
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> counter;
        vector<string> res;

        if (s.size() < 10) return res;

        for (int i=0; i<s.size()-9; i++)
            counter[s.substr(i, 10)]++;

        for (auto a:counter)
            if (a.second > 1)
                res.push_back(a.first);

        return res;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-28 21:45:57
 *   Description   ：
 */
using namespace std;
class Solution {
public:
int distributeCandies(vector<int>& c) {
    return min(unordered_set<int>(begin(c), end(c)).size(), c.size() / 2);
}
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-24 20:43:19
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& c) {
        int s = 0, e = c.size() - 1, avg;

        sort(begin(c), end(c));

        while (s <= e) {
            if (c[avg = (e + s) / 2] < c.size() - avg) s = avg + 1;
            else e = avg - 1;
        }
        return c.size() - s;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-06-05 11:21:47
 *   Description   ：
 */
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majorityIndex = 0;
        for (int count = 1, i = 1; i < num.size(); i++) {
            num[majorityIndex] == num[i] ? count++ : count--;
            if (count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }

        return num[majorityIndex];
    }
};





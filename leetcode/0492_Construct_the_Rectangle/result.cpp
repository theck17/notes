/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-22 09:53:38
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int mid = sqrt(area);
        while(mid > 0){
            if(area % mid == 0) return {area/mid, mid};
            mid--;
        }
        return {0, 0};
    }
};


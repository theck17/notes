/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-11 20:55:50
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        int count = 0, i = 0, n = points.size();
        while (i < n) {
            int maxVal = points[i][1];
            while (i < n && points[i][0] <= maxVal) 
                maxVal = min(maxVal, points[i++][1]);
            count++;
        }
        return count;
    }
};

int main(){
    return 0;
}

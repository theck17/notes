/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-22 20:14:15
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0)
            return 0;
        int res = 0;
        for(int i=0; i<timeSeries.size()-1; i++) {
            if (timeSeries[i+1] - timeSeries[i] < duration)
                res += timeSeries[i+1] - timeSeries[i];
            else
                res += duration;
        }
        return res+duration;
    }
};

int main(){
    return 0;
}

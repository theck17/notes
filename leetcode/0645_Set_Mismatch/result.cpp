/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-03 08:56:09
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // support variables
        int len = nums.size();
        bool seen[len + 1];
        vector<int> res(2);
        // preparing seen
        for (int i = 1; i <= len; i++) seen[i] = false;
        // parsing nums and finding the first part of res
        for (int i: nums) seen[i] = (!seen[i] || bool(1 + (res[0] = i)));
        // parsing seen and finding the second part of res
        for (int i = 1; i <= len; i++) if (!seen[i]) return res[1] = i, res;
        return res;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-18 19:32:32
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        for (int num : nums) {
            mset.insert(num);
            if (mset.size() > k) {
                mset.erase(mset.begin());
            }
        }
        return *mset.begin();
    }
};

int main(){
    return 0;
}

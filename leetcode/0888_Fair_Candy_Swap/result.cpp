/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-30 10:54:51
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int diff = (accumulate(aliceSizes.begin(), aliceSizes.end(), 0) - 
                    accumulate(bobSizes.begin(), bobSizes.end(), 0))/2;
        for (auto i : aliceSizes ) 
            if(find(bobSizes.begin(), bobSizes.end(), i - diff) != bobSizes.end())
                return {i,  i - diff};
        return {};
    }
};

int main(){
    return 0;
}

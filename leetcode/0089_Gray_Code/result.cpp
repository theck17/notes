/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-25 21:03:32
 *   Description   ：
 */
using namespace std;
class Solution {
    void utils(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());
        }
        else {
            utils(bits, result, k-1);
            bits.flip(k-1);
            utils(bits, result, k-1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        utils(bits, result, n);
        return result;
    }
};

int main(){
    return 0;
}

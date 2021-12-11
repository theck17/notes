/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-11 12:16:17
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> pos(k, 0);
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            int temp = INT_MAX;
            for (int j = 0; j < k; j++) 
                temp = min(temp, res[pos[j]] * primes[j]);
            for (int j = 0; j < k; j++) {
                if (temp == res[pos[j]] * primes[j])
                    pos[j]++;
            }
            res[i] = temp;
        }
        return res[n - 1];
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-23 10:46:25
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int guessNumber(int n) {
        int maxNumber = n, minNumber = 1;
        while (true) {
            int meanNumber = (maxNumber - minNumber) / 2 + minNumber;
            // Do NOT use (maxNumber+minNumber)/2 in case of over flow
            int res = guess(meanNumber);
            if (res == 0) { 
                return meanNumber;
            } else if (res == 1) {
                minNumber = meanNumber + 1;
            } else {
                maxNumber = meanNumber - 1;
            }
        }
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-04 21:50:26
 *   Description   ：
 */
using namespace std;


class Solution {
public:
   int maxProfit(vector<int>& prices) {
          int sum = 0;  // to store result
        int minCost = prices[0];  // initialise minimum cost as first day price
        int maxProfit = 0;  // initially profit is zero
        for(int i = 1; i < prices.size(); i++) {    // Now check from day 2
            if(prices[i] > minCost && prices[i] > prices[i-1]) {  // if current day price is better than previous day price & also greater than minimum cost so that to get maximum profit till date
                maxProfit = max(maxProfit, prices[i] - minCost);
                cout << maxProfit << " ";
            } else {      // since current day price is less as compared to previous also we have got maximum profit till date
                sum = sum + maxProfit;
                minCost = prices[i];   // Again we will set minimum cost as current day price
                maxProfit = 0;      // Now again from next day we will buy i.e maximum profit is now zero in hand
            }
       }
        sum = sum + maxProfit;
        return sum;
    }
}; 



int main(){
    return 0;
}

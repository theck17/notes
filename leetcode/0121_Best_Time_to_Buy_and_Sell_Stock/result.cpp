/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-03 19:11:18
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		//init ans,min_num,max_num
        int ans = 0;
        int min_num = INT_MAX;
        int max_num = INT_MIN;
		//read all num
        for(int i=0;i<prices.size();i++){
			//update min and max;
            min_num = min(prices[i],min_num);
            max_num = max(prices[i],max_num);
			//if min_num just update init the max_num,
			//cause max shoud appear after min
            if(min_num==prices[i]){
                max_num = INT_MIN;
			//else update ans
            }else{ans = max(ans,max_num-min_num);}
        }
        return ans;
    }
};




int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-03-24 19:28:18
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& cand, int sum, int start, vector<int> v){
        if(sum < 0){    // if sum < 0 solution is not found.
            return;
        }
        else if(sum == 0){  // if sum == 0 it means we have found a solution.
            ans.push_back(v);
            return;
        }
        for(int i=start;i<cand.size();i++){
            if(i > start && cand[i] == cand[i-1]){  // To avoid duplicates.
                continue;
            }
            if(sum-cand[i] < 0) {   // No point of searching further if sum-cand[i] < 0.
                break;
            }
            // Backtracking
            v.push_back(cand[i]);
            solve(cand,sum-cand[i],i+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        vector<int> v;
        solve(cand, target, 0, v);
        return ans;
    }
};




int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-19 20:48:11
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        
        int maxC = 0;
        for(int i = 0; i<n; i++) {
            int c = 0;
            bool found = false;
            for(int j = 0; j<n; j++) {
                if(nums[j] == nums[i]+1 || nums[j] == nums[i]) {
                    if(nums[i] != nums[j])
                        found = true; //To avoid cases like {1, 1, 1, 1, 1} output should be 0
                    c++;
                }
            }
            if(found)
                maxC = max(maxC, c);
            
        }
        return maxC;
    }
};

int main(){
    return 0;
}

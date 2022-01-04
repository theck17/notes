/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-04 21:23:32
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int number;
        unordered_map<int,pair<int,vector<int>>> hashmap;
        for(int i=0;i<nums.size();i++)
        {
            number  = nums[i];
            hashmap[number].first++;
            hashmap[number].second.push_back(i);
        }
        int degree = -1;
        for(auto it:hashmap)
        {
            if(it.second.first>degree){
                degree = it.second.first;
            }
        }
        
        int ans = nums.size();
            
        for(auto it:hashmap)
        {
            if(it.second.first==degree){
                int minimum = *min_element(it.second.second.begin(),it.second.second.end());
                int maximum = *max_element(it.second.second.begin(),it.second.second.end());
                
                if(maximum-minimum<ans){
                    ans = maximum - minimum;
                }
                
            }
        }
        
        return ans+1;
    
};}

int main(){
    return 0;
}

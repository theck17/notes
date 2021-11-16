/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-16 21:09:56
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> m;
        unsigned int longestContArray = 0;
        
            for(int i=0;i<nums.size();i++){
            sum += (nums[i]==0)?-1:1;
            
            auto it = m.find(sum);
            
            if(sum == 0){
                if(longestContArray < i+1)
                longestContArray = i+1;
            }
            else if(it != m.end()){
                if(longestContArray < i-it->second)
                longestContArray = i-it->second;
            }
            else if(it == m.end())
                    m.insert({sum,i});
        }
            return longestContArray;
    }
};

int main(){
    return 0;
}

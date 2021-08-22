/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-22 10:15:47
 *   Description   ：
 */
#include <ctime>           //定义关于时间的函数
using namespace std;
class Solution {
public:
    // unordered_map<int,vector<int>> mp;
    
    vector<int> arr;
    Solution(vector<int>& nums) {
       arr=nums;
    }
    
    int pick(int target) {
        
         //we are traversing the array again and storing the indices and then we pick a random index from it
        vector<int> indices;
        for(int i=0;i<arr.size();++i)
        {
            if(arr[i]==target)
                indices.push_back(i);
        }
        return indices[rand()%indices.size()];
    }
};

int main(){
    return 0;
}

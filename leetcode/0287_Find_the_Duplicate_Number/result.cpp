/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-24 12:28:57
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int low=1;
        int high=n;
        int mid;
        while(low<high){
            mid=(low+high)/2;
            int count=0;
            for(int num:nums){
                if(num<=mid) count++;
            }
            if(count>mid) high=mid;
            else low=mid+1; 
        }
        return low;
    }
};

int main(){
    return 0;
}

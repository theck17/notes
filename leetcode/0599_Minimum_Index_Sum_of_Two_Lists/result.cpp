/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-21 22:39:12
 *   Description   ：
 */
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        vector<string> res;
        int indexSum = INT_MAX;
        
        unordered_map<string, int> mp;
        
        for(int i=0; i<list1.size(); i++)
            mp[list1[i]] = i;
        
        for(int i=0; i<list2.size(); i++)
        {
            if(mp.find(list2[i]) != mp.end())
            {
                if(mp[list2[i]] + i < indexSum)
                {
                    indexSum = mp[list2[i]] + i;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if(mp[list2[i]] + i == indexSum)
                    res.push_back(list2[i]);
            }    
        }
        
        return res;
    }
};
int main(){
    return 0;
}

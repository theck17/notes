/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-02 19:34:41
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        priority_queue<pair<int,char>> maxheap;
        for(char c: s)
            freq[c]++;
        for(auto it: freq)
            maxheap.push({it.second,it.first});
        s="";   
        while(!maxheap.empty()){
            s+=string(maxheap.top().first,maxheap.top().second);
            maxheap.pop();
        }
        return s;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-15 20:05:31
 *   Description   ：
 */
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push(make_pair(score[i],i));
        }
        vector<string> res(score.size(),"");
        int count = 1;
        for(int i=0; i<score.size();i++)
        {
            if(count==1) {res[pq.top().second] = "Gold Medal"; count++;}
            else if(count==2) {res[pq.top().second] = "Silver Medal"; count++;}
            else if(count==3) {res[pq.top().second] = "Bronze Medal"; count++;}
            else {res[pq.top().second] = to_string(count); count++;}
            pq.pop();
        }
        return res;
    }
};
int main(){
    return 0;
}
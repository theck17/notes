/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-10-28 21:31:42
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {        
        typedef pair<int, int> Event;
        vector<Event> events;
        for(auto a: buildings){
            events.emplace_back(a[0], a[2]);
            events.emplace_back(a[1], -a[2]);
        }
        
        sort(events.begin(), events.end(), [](const Event& ev1, const Event& ev2){
            if(ev1.first == ev2.first) return ev1.second > ev2.second;
            else return ev1.first < ev2.first;
            //return ev1.first == ev2.first ? ev1.second > ev2.second : ev1.first < ev2.first; //ok
            }
        );
        
        vector<vector<int>> ans;
        for(const auto& ev: events){
            int x = ev.first;
            int h = ev.second;
            bool enter = h > 0;
            h = abs(h);
            
            if(enter){
                if(h > maxHeight())
                    ans.push_back({x, h});
                hs_.insert(h);
            }else{
                /hs_.remove(hs_.equal_range(h).first);
                hs_.erase(hs_.equal_range(h).first);
                if(h > maxHeight())
                    ans.push_back({x, maxHeight()});
            }
        }
        return ans;
    }
    
private:
    multiset<int> hs_;
    int maxHeight(){
        return hs_.empty() ? 0 : *hs_.rbegin();
    } 
};/

int main(){
    return 0;
}

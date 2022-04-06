/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-14 19:30:38
 *   Description   ：
 */
using namespace std;
class Solution {
    struct compare {
        bool operator() (pair<int, int>p1, pair<int, int>p2) {
            return p1.first + p1.second < p2.first + p2.second;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            for (int j = 0; j < min((int)nums2.size(), k); j++) {
                if (pq.size() < k)
                    pq.push(make_pair(nums1[i], nums2[j]));
                else if (pq.top().first + pq.top().second > nums1[i] + nums2[j]) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }   
            }
        }
        
        while (!pq.empty()) {
            pair<int, int>p = pq.top();
            pq.pop();
            vector<int>v{p.first, p.second};
            res.push_back(v);
       }
        
        return res;
    }
}; 


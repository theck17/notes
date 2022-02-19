/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-19 10:52:05
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        vector<int> degree(numCourses, 0), bfs;
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < numCourses; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size() == numCourses;
    }
};

int main(){
    return 0;
}

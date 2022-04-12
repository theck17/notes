/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-26 18:58:47
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    vector<string> result;
    string solution;
    
    vector<string> restoreIpAddresses(string s) {
        
        backtracking(s, 0, 0);
        
        return result;
    }
    
private:
    void backtracking(string s, int start, int part)
    {
        if(start == s.size() && part == 4)
        {
            result.push_back(solution);
            return;
        }
        
        for(int i = start; i < s.size(); i++)
        {
            if(part < 4 && i-start < 3 && validIP(s, start, i))
            {
                solution.append(s.substr(start, i-start+1));
                part++;
                if(part < 4) solution.push_back('.');

                backtracking(s, i+1, part);
                
                if(part < 4) solution.pop_back();
                part--;
                for(int j = 0; j < i-start+1; j++) solution.pop_back();
            }
        }
    }
    
    bool validIP(string s, int start, int end)
    {
        string temp = s.substr(star, end-start+1);
        int ip = stoll(temp);
        
        if(s[start] == '0' && start != end) return false;
        else if(ip >= 0 && ip <= 255) return true;
        
        return false;
    }
};t

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-08 11:43:52
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        int value1;
        int value2;
        int ans = 0;
        stack<int>stk;
        
        for(string i:ops)
        {
            if(i == "C")
            {
                stk.pop();
            }
            else if(i == "D")
            {
                stk.push(stk.top()*2);
            }
            else if(i == "+")
            {
                value1 = stk.top();
                stk.pop();
                value2 = stk.top();
                stk.push(value1);
                stk.push(value1 + value2);
            }
            else
            {
                stk.push(stoi(i)); //stoi() to convert string into integer 
            }
        }
        while(stk.size() != 0)
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main(){
    return 0;
}

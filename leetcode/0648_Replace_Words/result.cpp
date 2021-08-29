/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-29 12:32:49
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <ctime>           //定义关于时间的函数
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> root;
        string new_sent = "", suc;
        
        for(const auto &x : dictionary) {
            root.insert(x);
        }
        
        stringstream ss(sentence);
        
        while(ss >> suc) {            
            string str = "";
            for(const auto & c : suc) {
                str += c;
                if(root.count(str)) {
                    suc = str;
                    break;
                }
            }            
            if(new_sent == "") new_sent += suc;
            else new_sent = new_sent + ' ' + suc;
        }        
        return new_sent;
    }
};

int main(){
    return 0;
}

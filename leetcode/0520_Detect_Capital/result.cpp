/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-30 21:20:55
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int a=0,b=0,c=0;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]>=65&&word[i]<=90)
            {
                a++;
                c=i;
            }
            else if(word[i]>=97&&word[i]<=122)            
                b++;            
         }
        if(a==word.length())
            return true;
        else if(a==1&&c==0&&word.length()-1==b)
            return true;
        else if(b==word.length())
            return true;
        else
            return false;
    }
};

int main(){
    return 0;
}

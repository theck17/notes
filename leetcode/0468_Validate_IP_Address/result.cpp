/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-03 19:40:39
 *   Description   ：
 */
using namespace std;
class Solution 
{
public:
    string validIPAddress(string IP) 
    {
      int n=IP.length();
      int cnt4=0,iv4=1,cnt6=0;
        for(int i=0;i<n;i++)
        {
            if(IP[i]=='.')
                cnt4++;
            if(cnt4!=0&&IP[i]==':')
                return "Neither";
            if(IP[i]==':')
                cnt6++;
            if(cnt6!=0&&IP[i]=='.')
                 return "Neither";
        }
        //cout<<cnt6<<"\n";
        if(cnt4!=0&&cnt4!=3)
             return "Neither";
        if(cnt6!=0&&cnt6!=7)
              return "Neither";
        if(cnt4!=0)
        {
            stringstream ss(IP);
            string word;
            while(getline(ss,word,'.'))
            {
                if(word.length()==0||word.length()>3||word[0]=='-')
                    return "Neither";
                if(word[0]=='0'&&word.length()>1)
                     return "Neither";
                for(int i=0;i<word.length();i++)
                {
                    if(!(word[i]>='0'&&word[]<='9'))
                        return "Neither";
                }
                stringstream pp(word);
                int a=0;
                pp>>a;
                if(a<0||a>255)
                     return "Neither";
            }
            if(word.length()==0||word.length()>3)
                    return "Neither";
              if(word[0]=='0'&&word.length()>1)
                     return "Neither";
            for(int i=0;i<word.length();i++)
                {
                    if(word[i]=='e')
                        return "Neither";
                }
                stringstream pp(word);
                int a=0;
                pp>>a;
                if(a<0||a>255)
                     return "Neither";
        }
        else 
        {
             stringstream ss(IP);
            string word;
            while(getline(ss,word,':'))
            {
               // cout<<word<<"\n";
              for(int i=0;i<word.length();i++)
              {
                if(!((word[i]>='0'&&word[i]<='9')||(word[i]>='a'&&word[i]<='f')||(word[i]>='A'&&word[i]<='F')))
                 return "Neither";
              }
                if(word.length()>4||word.length()==0||word[0]=='-')
                    return "Neither";
                if(word[0]=='0'&&word.length()>4)
                     return "Neither";
            }
            if(word.length()>4||word.length()==0)
                    return "Neither";
                if(word[0]=='0'&&word.length()>4)
                     return "Neither";
        }
        if(cnt4!=0)
            return "IPv4";
        
        return "IPv6";
    }
};i

int main(){
    return 0;
}

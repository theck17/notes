/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-01 09:41:00
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        for (auto i = S.rbegin(); i < S.rend(); i++)
            if (*i != '-') { // ignore '-' in original string
                if (res.size()%(K+1) == K) res += '-'; // every (K+1)th char is '-' from tail
                res += toupper(*i);
            }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-08-26 22:34:02
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
using namespace std;
class Solution {
public:
	int compress(vector<char>& chars) {
		if(chars.size() < 2)
			return chars.size();

		int  i = 0;
		int  j = 0;

		while(i < chars.size()) {
			chars[j] = chars[i];
			int cnt = 0;
			while(i < chars.size() && chars[i] == chars[j]) {
				cnt++;
				i++;
			}

			if(cnt == 1) {
				j++;
			} else {
				string str = to_string(cnt);
				for(auto ch: str)
					chars[++j] = ch;
				j++;
			}
		}

		return j;
	}
};

int main(){
    return 0;
}

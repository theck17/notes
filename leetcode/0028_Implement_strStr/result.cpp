/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-07-11 12:36:10
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nsize = needle.size();
    	int hsize = haystack.size();
    	if (nsize == 0) return 0;
    	int *table = new int[nsize];
    	memset(table, 0, sizeof(int)*nsize);
    	//building match table
    	for (int i = 1, j = 0; i < nsize - 1;){
    		if (needle[i] != needle[j]){
    			if (j>0){
    				j = table[j - 1];
    			}
    			else{
    				i++;
    			}
    		}
    		else{
    			table[i] = j + 1;
    			i++;
    			j++;
    		}
    	}
    	//matching
    	for (int i = 0, match_pos = 0; i < hsize;){
    		if (haystack[i] == needle[match_pos]){
    			if (match_pos == nsize - 1){
    				return i - (nsize - 1);
    			}
    			else{
    				i++;
    				match_pos++;
    			}
    		}
    		else{
    			if (match_pos == 0){
    				i++;
    			}
    			else{
    				match_pos = table[match_pos - 1];
    			}
    		}
    	}
    	delete[]table;
    	return -1;
    }
};

int main(){
    return 0;
}

/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-03 20:10:59
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
      int x = abs(num); string res;
      do res = to_string(x%7)+res; while(x/=7);
      return (num>=0? "" : "-") + res;
    }
};

int main(){
    return 0;
}

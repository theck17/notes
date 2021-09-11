/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-11 10:15:23
 *   Description   ：
 */
bool isIsomorphic(char* s, char* t) {
  for (int i = 0; i < strlen (s); i++)
    if ((strchr (s,s[i]) - s) != (strchr(t,t[i]) - t)) return false;
  return true;
}

int main(){
    return 0;
}

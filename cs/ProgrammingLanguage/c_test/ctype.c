/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：ctype.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-01 19:51:07
 *   Description   ：
 */

#include <ctype.h>
#include <stdio.h>

int main() {
  int var1 = 'd';
  int var2 = '2';
  int var3 = '\t';
  int var4 = ' ';
  int var5 = 85; // ascii码

  if (isalnum(var1)) {
    printf("var1 = |%c| 是字母数字\n", var1);
  } else {
    printf("var1 = |%c| 不是字母数字\n", var1);
  }
  if (isalnum(var2)) {
    printf("var2 = |%c| 是字母数字\n", var2);
  } else {
    printf("var2 = |%c| 不是字母数字\n", var2);
  }
  if (isalnum(var3)) {
    printf("var3 = |%c| 是字母数字\n", var3);
  } else {
    printf("var3 = |%c| 不是字母数字\n", var3);
  }
  if (isalnum(var4)) {
    printf("var4 = |%c| 是字母数字\n", var4);
  } else {
    printf("var4 = |%c| 不是字母数字\n", var4);
  }
  if (isalnum(var5)) {
    printf("var5 = |%c| is digital or The letter\n", var5);
  } else {
    printf("var5 = |%c| is not digital or The letter\n", var5);
  }

  return (0);
}

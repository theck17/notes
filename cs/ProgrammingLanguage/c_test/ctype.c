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

  int i = 0, j = 0;
  char str1[] = "hello \a colin h \n knight";
  char str2[] = "world \n 123 ";

  /* 输出字符串直到控制字符 \a */
  while (!iscntrl(str1[i])) {
    putchar(str1[i]);
    i++;
  }

  /* 输出字符串直到控制字符 \n */
  while (!iscntrl(str2[j])) {
    putchar(str2[j]);
    j++;
  }
  printf("\n");

  int var6 = '3';
  int var7 = 'm';
  int var8 = ' ';

  if (isgraph(var6)) {
    printf("var6 = |%c| 是可打印的\n", var6);
  } else {
    printf("var6 = |%c| 是不可打印的\n", var6);
  }
  if (isgraph(var7)) {
    printf("var7 = |%c| 是可打印的\n", var7);
  } else {
    printf("var7 = |%c| 是不可打印的\n", var7);
  }
  if (isgraph(var8)) {
    printf("var8 = |%c| 是可打印的\n", var8);
  } else {
    printf("var8 = |%c| 是不可打印的\n", var8);
  }

  int var9 = 'k';
  int var10 = '8';
  int var11 = '\t';
  int var12 = ' ';

  if (isprint(var9)) {
    printf("var9 = |%c| 是可打印的\n", var9);
  } else {
    printf("var9 = |%c| 是不可打印的\n", var9);
  }
  if (isprint(var10)) {
    printf("var10 = |%c| 是可打印的\n", var10);
  } else {
    printf("var10 = |%c| 是不可打印的\n", var10);
  }
  if (isprint(var11)) {
    printf("var11 = |%c| 是可打印的\n", var11);
  } else {
    printf("var11 = |%c| 是不可打印的\n", var11);
  }
  if (isprint(var12)) {
    printf("var12 = |%c| 是可打印的\n", var12);
  } else {
    printf("var12 = |%c| 是不可打印的\n", var12);
  }

  char var13[] = "tuts";
  char var14[] = "0xE";

  if (isxdigit(var13[0])) {
    printf("var13 = |%s| 是十六进制数字\n", var13);
  } else {
    printf("var13 = |%s| 不是十六进制数字\n", var13);
  }

  if (isxdigit(var14[0])) {
    printf("var14 = |%s| 是十六进制数字\n", var14);
  } else {
    printf("var14 = |%s| 不是十六进制数字\n", var14);
  }

  return (0);
}

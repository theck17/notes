/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：test.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-02-01 19:30:42
 *   Description   ：
 */

#include <assert.h>
#include <stdio.h>

int main() {
  int a;
  char str[50];

  printf("请输入一个整数值： ");
  scanf("%d\n", &a);
  assert(a >= 10);
  printf("输入的整数是： %d\n", a);

  printf("请输入字符串： ");
  scanf("%s\n", str);
  assert(str != NULL);
  printf("输入的字符串是： %s\n", str);

  return (0);
}

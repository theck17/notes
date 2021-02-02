/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-21 21:41:50
 *   Description   ：
 */
#include <ctype.h>  //字符函数
#include <stdlib.h> //动态分配函数和随机函数
#include <string.h> //字符串函数

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
  int *result = malloc(sizeof(int) * (digitsSize + 1));
  if (!digitsSize) {
    *returnSize = 0;
    return result;
  }

  int carry = 1;
  for (int i = digitsSize - 1; i >= 0; i--) {
    result[i + 1] = digits[i] + carry;
    carry = result[i + 1] / 10;
    result[i + 1] = result[i + 1] % 10;
  }
  if (carry == 1) {
    result[0] = 1;
    *returnSize = digitsSize + 1;
    return result;
  } else {
    *returnSize = digitsSize;
    return result + 1;
  }
}

int main() { return 0; }

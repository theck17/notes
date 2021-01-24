/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-24 13:49:42
 *   Description   ：
 */
#include <ctype.h>  //字符函数
#include <math.h>   //数学函数
#include <stdio.h>  //输入输出函数
#include <stdlib.h> //动态分配函数和随机函数
#include <string.h> //字符串函数

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  if (n == 0)
    return;
  if (m == 0 && n != 0) {
    for (int i = 0; i < n; i++)
      nums1[i] = nums2[i];
    return;
  }
  int *p1 = &nums1[0], *p2 = &nums2[0];
  int c = 0, res[m + n], rc = 0, c1 = m;
  for (int i = 0; i < m + n; i++)
    res[i] = 0;
  while (c < m + n) {
    if (*p2 <= *p1) {
      res[rc] = *p2;
      rc++;
      c++;
      if (p2 == &nums2[n - 1]) {
        for (int i = c; i < m + n; i++) {
          res[rc] = *p1;
          p1++;
          rc++;
        }
        break;
      }
      p2++;
    } else if (*p1 < *p2) {
      c1--;
      res[rc] = *p1;
      p1++;
      rc++;
      c++;
    }
    if (p1 != &nums1[0] && c1 == 0) {
      for (int i = c; i < m + n; i++) {
        res[rc] = *p2;
        p2++;
        rc++;
      }
      break;
    }
  }
  for (c = 0; c < m + n; c++)
    nums1[c] = res[c];
}

int main() { return 0; }

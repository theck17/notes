/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-17 15:11:49
 *   Description   ：
 */
#define MIN(i, j) ((i) < (j) ? (i) : (j))
#define MAX(i, j) ((i) < (j) ? (j) : (i))


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
  int LX1, LX2, RX1, RX2, J, K;
  int LY1, LY2, RY1, RY2;
  int interx, intery;
  
  // assume C > A, D > B, G > E, H > F
  
  // let's determine the "left" rectangle if looking from above, i.e. only caring about x axis
  if (A < E) {
    LX1 = A;
    LX2 = C;
    RX1 = E;
    RX2 = G;
  } else {
    LX1 = E;
    LX2 = G;
    RX1 = A;
    RX2 = C;
  }
  
  // J is the start of the intersection
  J = MAX(LX1, RX1);
  // K is the end of the intersection
  K = MIN(LX2, RX2);
  // if J > K then there is no intersection in this dimension
  interx = (K > J) ? (K - J) : 0;
  
  // do the same thing for Y dimension
  // but only if there is x axis intersection
  if (interx != 0) {
    if (B < F) { 
      LY1 = B;
      LY2 = D;
      RY1 = F;
      RY2 = H;
    } else {
      LY1 = F;
      LY2 = H;
      RY1 = B;
      RY2 = D;
    }
  
    J = MAX(LY, RY1);
    K = MIN(LY2, RY2);
    intery = (K > J) ? (K - J) : 0;
  } else {
    intery = 0;
  }
  
  // important: subtract the intersection before adding the second rectangle to avoid overflow
  return (C - A) * (D - B) - interx * intery + (G - E) * (H - F);
}1


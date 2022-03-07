/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-17 15:11:13
 *   Description   ：
 */
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B);
        int s2 = (G - E) * (H - F); 
        if (A >= G || C <= E || D <= F || B >= H)
            return s1 + s2; 
        return s1 - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F)) + s2;
    }
};


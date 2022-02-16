/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-16 08:04:38
 *   Description   ：
 */
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    double result = 0;
    for (int i = 0; i < pointsSize; i++)
        for (int j = i + 1; j < pointsSize; j++)
            for (int k = j + 1; k < pointsSize; k++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int x3 = points[k][0], y3 = points[k][1];
                double area = fabs(0.50000 * (x2 * y3 + x1 * y2 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3));
                result = result > area ? result : area;
            }
    return result;
}

int main(){
    return 0;
}

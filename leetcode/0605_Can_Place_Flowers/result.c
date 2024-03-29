/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-15 17:09:24
 *   Description   ：
 */
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int i;
    int prev = 0;
    
    for (i = 0; i < flowerbedSize-1; i++) {
        if (flowerbed[i] == 0 && prev == 0 && flowerbed[i+1] == 0) {
            prev = 1; /*  seed in the hold now */
            n--;
        }
        else {
            prev = flowerbed[i];
        }
    }
    
	/* last elment */
    if (flowerbed[i] == 0 && prev == 0) {
        n--;
    }
    
    return n <= 0; /* if there are available holes more than seeds, n < 0 */
}

int main(){
    return 0;
}

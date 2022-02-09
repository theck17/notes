/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-09 09:46:44
 *   Description   ：
 */
bool judgeCircle(char * moves){
    int i=0;

    int x = 0, y = 0; 

    for (i=0;moves[i] !='\0';i++) {
        if (moves[i] == 'U') y--;
        else if (moves[i] == 'D') y++;
        else if (moves[i] == 'L') x--;
        else if (moves[i] == 'R') x++;
    }
    return x == 0 && y == 0;
}

int main(){
    return 0;
}

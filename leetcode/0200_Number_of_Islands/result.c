/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-20 10:11:52
 *   Description   ：
 */
int numIslands(char** grid, int gridSize, int* gridColSize){
    int ** visited = malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < gridSize; i++){
        visited[i] = malloc(sizeof(int) * gridColSize[i]);
        for (int j = 0; j < gridColSize[i]; j++){
            visited[i][j] = 0;
        }
    }
    int result = 0;
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++){
            if (visited[i][j] == 1)
                continue;
            if (grid[i][j] == '1'){
                result += 1;
                findadj(grid, i, j, &visited, gridSize, gridColSize[0]);
            }
        }
    }
    return result;
}

void findadj(char ** grid, int row, int col, int *** visited, int gridSize, int gridColSize){
    if (row < 0 || col < 0 || row >= gridSize || col >= gridColSize)
        return;
    //printf("row = %d, col = %d\n", row, col);
    if ((*visited)[row][col] == 1){
        return;
    }
    (*visited)[row][col] = 1;
    if (grid[row][col] == '0')
       return;
    findadj(grid, row - 1, col, visited, gridSize, gridColSize);
    findadj(grid, row + 1, col, visited, gridSize, gridColSize);
    findadj(grid, row, col - 1, visited, gridSize, gridColSize);
    findadj(grid, row, col + 1, visited, gridSize, gridColSize);
    return;
} 

int main(){
    return 0;
}

int dfs(int** grid, int r, int c, int R, int C) {
    if (r < 0 || c < 0 || r >= R || c >= C) return 0;
    if (grid[r][c] == 1) return 1;
    
    grid[r][c] = 1;
    
    int up = dfs(grid, r - 1, c, R, C);
    int down = dfs(grid, r + 1, c, R, C);
    int left = dfs(grid, r, c - 1, R, C);
    int right = dfs(grid, r, c + 1, R, C);
    
    return up & down & left & right;
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    int R = gridSize;
    int C = gridColSize[0];
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 0) {
                if (dfs(grid, i, j, R, C)) {
                    count++;
                }
            }
        }
    }
    
    return count;
}
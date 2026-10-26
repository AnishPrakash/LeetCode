long long dfs(int** grid, int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
        return 0;
    }
    long long val = grid[r][c];
    grid[r][c] = 0;
    val += dfs(grid, r + 1, c, rows, cols);
    val += dfs(grid, r - 1, c, rows, cols);
    val += dfs(grid, r, c + 1, rows, cols);
    val += dfs(grid, r, c - 1, rows, cols);
    return val;
}

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int count = 0;
    int rows = gridSize;
    if (rows == 0) return 0;
    int cols = gridColSize[0];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] > 0) {
                long long sum = dfs(grid, i, j, rows, cols);
                if (sum % k == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}
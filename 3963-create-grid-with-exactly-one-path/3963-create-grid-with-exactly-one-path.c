char** createGrid(int m, int n, int* returnSize) {
    *returnSize = m;
    char** grid = (char**)malloc(m * sizeof(char*));
    
    for (int i = 0; i < m; i++) {
        grid[i] = (char*)malloc((n + 1) * sizeof(char));
        memset(grid[i], '#', n);
        grid[i][n] = '\0';
    }

    for (int j = 0; j < n; j++) {
        grid[0][j] = '.';
    }

    for (int i = 0; i < m; i++) {
        grid[i][n - 1] = '.';
    }

    return grid;
}
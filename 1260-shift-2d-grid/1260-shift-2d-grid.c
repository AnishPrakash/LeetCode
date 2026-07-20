int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    int total = m * n;
    k = k % total;

    int** res = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int new_pos = (i * n + j + k) % total;
            res[new_pos / n][new_pos % n] = grid[i][j];
        }
    }

    return res;
}
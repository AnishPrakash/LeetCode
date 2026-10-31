int uniquePaths(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int MOD = 1000000007;
    int** R = (int**)malloc(m * sizeof(int*));
    int** D = (int**)malloc(m * sizeof(int*));
    
    for (int i = 0; i < m; i++) {
        R[i] = (int*)calloc(n, sizeof(int));
        D[i] = (int*)calloc(n, sizeof(int));
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                if (j + 1 < n) R[0][1] = 1;
                if (i + 1 < m) D[1][0] = 1;
                continue;
            }
            
            int r = R[i][j];
            int d = D[i][j];
            
            if (grid[i][j] == 0) {
                int w = (r + d) % MOD;
                if (i == m - 1 && j == n - 1) {
                    for (int k = 0; k < m; k++) {
                        free(R[k]);
                        free(D[k]);
                    }
                    free(R);
                    free(D);
                    return w;
                }
                if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + w) % MOD;
                if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + w) % MOD;
            } else {
                if (i + 1 < m) D[i + 1][j] = (D[i + 1][j] + r) % MOD;
                if (j + 1 < n) R[i][j + 1] = (R[i][j + 1] + d) % MOD;
            }
        }
    }
    
    for (int k = 0; k < m; k++) {
        free(R[k]);
        free(D[k]);
    }
    free(R);
    free(D);
    
    return 0;
}
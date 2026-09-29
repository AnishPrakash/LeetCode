bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int max_len = m + n - 1;
    
    if (max_len % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
        return false;
    }
    
    bool dp[105][205];
    memset(dp, 0, sizeof(dp));
    dp[0][1] = true;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            
            int diff = (grid[i][j] == '(') ? 1 : -1;
            bool next_dp[205];
            memset(next_dp, 0, sizeof(next_dp));
            
            for (int k = 0; k <= max_len; k++) {
                int prev_k = k - diff;
                if (prev_k >= 0 && prev_k <= max_len) {
                    if (dp[j][prev_k]) {
                        next_dp[k] = true;
                    }
                    if (j > 0 && dp[j - 1][prev_k]) {
                        next_dp[k] = true;
                    }
                }
            }
            for(int k = 0; k <= max_len; k++) {
                dp[j][k] = next_dp[k];
            }
        }
    }
    
    return dp[n - 1][0];
}
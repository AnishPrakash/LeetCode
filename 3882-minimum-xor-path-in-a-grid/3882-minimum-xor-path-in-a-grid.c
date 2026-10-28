#include <stdlib.h>
#include <string.h>

int minCost(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    char (*dp)[1024] = calloc(n, 1024);
    
    int start_val = grid[0][0];
    dp[0][start_val] = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            
            char new_dp[1024] = {0};
            int val = grid[i][j];
            
            for (int k = 0; k < 1024; k++) {
                if ((i > 0 && dp[j][k]) || (j > 0 && dp[j - 1][k])) {
                    new_dp[k ^ val] = 1;
                }
            }
            
            for (int k = 0; k < 1024; k++) {
                dp[j][k] = new_dp[k];
            }
        }
    }
    
    int ans = 0;
    for (int k = 0; k < 1024; k++) {
        if (dp[n - 1][k]) {
            ans = k;
            break;
        }
    }
    
    free(dp);
    return ans;
}
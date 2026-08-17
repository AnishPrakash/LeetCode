int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int prefix[505] = {0};
    
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }
    
    int dp[505][505] = {0};
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            int max_score = 0;
            
            for (int k = i; k < j; ++k) {
                int left_sum = prefix[k + 1] - prefix[i];
                int right_sum = prefix[j + 1] - prefix[k + 1];
                
                if (left_sum < right_sum) {
                    if (left_sum + dp[i][k] > max_score) {
                        max_score = left_sum + dp[i][k];
                    }
                } else if (left_sum > right_sum) {
                    if (right_sum + dp[k + 1][j] > max_score) {
                        max_score = right_sum + dp[k + 1][j];
                    }
                } else {
                    int max_branch = dp[i][k] > dp[k + 1][j] ? dp[i][k] : dp[k + 1][j];
                    if (left_sum + max_branch > max_score) {
                        max_score = left_sum + max_branch;
                    }
                }
            }
            dp[i][j] = max_score;
        }
    }
    
    return dp[0][n - 1];
}
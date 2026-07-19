int minCost(char* source, char* target, char*** rules, int rulesSize, int* rulesColSize, int* costs, int costsSize) {
    int n = strlen(source);
    int m = strlen(target);
    
    if (n != m) {
        return -1;
    }
    
    const int INF = 1000000000;
    int dp[5005];
    int rl[205];
    int rc[205];
    
    for (int i = 0; i < rulesSize; i++) {
        rl[i] = strlen(rules[i][0]);
        int stars = 0;
        for (int k = 0; k < rl[i]; k++) {
            if (rules[i][0][k] == '*') {
                stars++;
            }
        }
        rc[i] = costs[i] + stars;
    }
    
    dp[n] = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = INF;
        
        if (source[i] == target[i]) {
            dp[i] = dp[i + 1];
        }
        
        for (int j = 0; j < rulesSize; j++) {
            int l = rl[j];
            if (i + l <= n) {
                int match = 1;
                char* p = rules[j][0];
                char* r = rules[j][1];
                
                for (int k = 0; k < l; k++) {
                    if (r[k] != target[i + k]) {
                        match = 0;
                        break;
                    }
                    if (p[k] != '*' && p[k] != source[i + k]) {
                        match = 0;
                        break;
                    }
                }
                
                if (match && dp[i + l] != INF) {
                    if (rc[j] + dp[i + l] < dp[i]) {
                        dp[i] = rc[j] + dp[i + l];
                    }
                }
            }
        }
    }
    
    return dp[0] == INF ? -1 : dp[0];
}
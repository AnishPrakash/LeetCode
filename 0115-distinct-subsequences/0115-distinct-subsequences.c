int numDistinct(char * s, char * t) {
    int m = strlen(s);
    int n = strlen(t);
    unsigned long long dp[1005] = {0};
    
    dp[0] = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= 1; j--) {
            if (s[i] == t[j-1]) {
                dp[j] += dp[j-1];
            }
        }
    }
    
    return (int)dp[n];
}
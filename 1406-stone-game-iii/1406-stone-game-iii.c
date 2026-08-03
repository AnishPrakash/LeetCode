char * stoneGameIII(int* stoneValue, int stoneValueSize) {
    int *dp = (int*)malloc((stoneValueSize + 1) * sizeof(int));
    dp[stoneValueSize] = 0;
    
    for (int i = stoneValueSize - 1; i >= 0; i--) {
        dp[i] = -1000000000;
        int take = 0;
        for (int j = 0; j < 3 && i + j < stoneValueSize; j++) {
            take += stoneValue[i + j];
            if (take - dp[i + j + 1] > dp[i]) {
                dp[i] = take - dp[i + j + 1];
            }
        }
    }
    
    int res = dp[0];
    free(dp);
    
    if (res > 0) return "Alice";
    if (res < 0) return "Bob";
    return "Tie";
}
bool stoneGame(int* piles, int pilesSize) {
    int dp[500];
    
    for (int i = 0; i < pilesSize; i++) {
        dp[i] = piles[i];
    }
    
    for (int len = 2; len <= pilesSize; len++) {
        for (int i = 0; i <= pilesSize - len; i++) {
            int j = i + len - 1;
            int left = piles[i] - dp[i + 1];
            int right = piles[j] - dp[i];
            dp[i] = left > right ? left : right;
        }
    }
    
    return dp[0] > 0;
}
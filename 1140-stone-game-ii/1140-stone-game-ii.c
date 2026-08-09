int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int i, int M, int* piles, int n, int dp[105][205], int* suffix) {
    if (i >= n) return 0;
    if (i + 2 * M >= n) return suffix[i];
    if (dp[i][M] != -1) return dp[i][M];

    int res = 0;
    for (int x = 1; x <= 2 * M; ++x) {
        int opponent = solve(i + x, max(M, x), piles, n, dp, suffix);
        int current = suffix[i] - opponent;
        if (current > res) {
            res = current;
        }
    }
    return dp[i][M] = res;
}

int stoneGameII(int* piles, int pilesSize) {
    int dp[105][205];
    for (int i = 0; i <= pilesSize; ++i) {
        for (int j = 0; j <= 200; ++j) {
            dp[i][j] = -1;
        }
    }
    int suffix[105] = {0};
    suffix[pilesSize - 1] = piles[pilesSize - 1];
    for (int i = pilesSize - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + piles[i];
    }
    return solve(0, 1, piles, pilesSize, dp, suffix);
}
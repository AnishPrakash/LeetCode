int gcd(int a, int b) {
    if (a == 0) return b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int subsequencePairCount(int* nums, int numsSize) {
    int MOD = 1000000007;
    int dp[201][201] = {0};
    int next_dp[201][201] = {0};
    
    dp[0][0] = 1;
    
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        
        for (int g1 = 0; g1 <= 200; g1++) {
            for (int g2 = 0; g2 <= 200; g2++) {
                next_dp[g1][g2] = dp[g1][g2];
            }
        }
        
        for (int g1 = 0; g1 <= 200; g1++) {
            for (int g2 = 0; g2 <= 200; g2++) {
                if (dp[g1][g2] > 0) {
                    int ng1 = gcd(g1, x);
                    int ng2 = gcd(g2, x);
                    
                    next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % MOD;
                    next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
        }
        
        for (int g1 = 0; g1 <= 200; g1++) {
            for (int g2 = 0; g2 <= 200; g2++) {
                dp[g1][g2] = next_dp[g1][g2];
            }
        }
    }
    
    int ans = 0;
    for (int g = 1; g <= 200; g++) {
        ans = (ans + dp[g][g]) % MOD;
    }
    
    return ans;
}
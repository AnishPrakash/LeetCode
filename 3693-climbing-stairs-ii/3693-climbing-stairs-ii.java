class Solution {
    public int climbStairs(int n, int[] costs) {
        int[] dp = new int[n + 1];
        
        for (int i = 1; i <= n; i++) {
            int minCost = Integer.MAX_VALUE;
            for (int k = 1; k <= 3; k++) {
                if (i - k >= 0) {
                    int costFromPrev = dp[i - k] + costs[i - 1] + (k * k);
                    minCost = Math.min(minCost, costFromPrev);
                }
            }
            dp[i] = minCost;
        }
        
        return dp[n];
    }
}
class Solution {
    public int minimumChanges(String s, int k) {
        int n = s.length();
        int[][] cost = new int[n][n];
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                cost[i][j] = len;
                for (int d = 1; d * 2 <= len; d++) {
                    if (len % d == 0) {
                        int currentCost = 0;
                        for (int start = 0; start < d; start++) {
                            int left = i + start;
                            int right = i + len - d + start;
                            while (left < right) {
                                if (s.charAt(left) != s.charAt(right)) {
                                    currentCost++;
                                }
                                left += d;
                                right -= d;
                            }
                        }
                        cost[i][j] = Math.min(cost[i][j], currentCost);
                    }
                }
            }
        }
        
        int[][] dp = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            for (int p = 0; p <= k; p++) {
                dp[i][p] = 1000000;
            }
        }
        
        for (int i = 1; i < n; i++) {
            dp[i][1] = cost[0][i];
        }
        
        for (int p = 2; p <= k; p++) {
            for (int i = p * 2 - 1; i < n; i++) {
                for (int j = (p - 1) * 2 - 1; j < i - 1; j++) {
                    dp[i][p] = Math.min(dp[i][p], dp[j][p - 1] + cost[j + 1][i]);
                }
            }
        }
        
        return dp[n - 1][k];
    }
}
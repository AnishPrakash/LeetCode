class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int maxFactor = 0;
        int minPrice = Integer.MAX_VALUE;
        for (int[] item : items) {
            if (item[0] > maxFactor) {
                maxFactor = item[0];
            }
            if (item[1] < minPrice) {
                minPrice = item[1];
            }
        }
        int[] freq = new int[maxFactor + 1];
        for (int[] item : items) {
            freq[item[0]]++;
        }
        int[] gain = new int[maxFactor + 1];
        for (int f = 1; f <= maxFactor; f++) {
            if (freq[f] > 0) {
                int count = 0;
                for (int m = f; m <= maxFactor; m += f) {
                    count += freq[m];
                }
                gain[f] = count;
            }
        }
        int[] dp = new int[budget + 1];
        for (int[] item : items) {
            int price = item[1];
            int val = gain[item[0]];
            for (int b = budget; b >= price; b--) {
                int candidate = dp[b - price] + val;
                if (candidate > dp[b]) {
                    dp[b] = candidate;
                }
            }
        }
        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            int total = dp[b] + (budget - b) / minPrice;
            if (total > ans) {
                ans = total;
            }
        }
        return ans;
    }
}
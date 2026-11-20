class Solution {
    public int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int maxVal = nums[nums.length - 1];
        int[] dp = new int[maxVal + 2];
        int ans = 0;
        for (int x : nums) {
            dp[x + 1] = Math.max(dp[x + 1], dp[x] + 1);
            dp[x] = Math.max(dp[x], dp[x - 1] + 1);
            ans = Math.max(ans, Math.max(dp[x], dp[x + 1]));
        }
        return ans;
    }
}
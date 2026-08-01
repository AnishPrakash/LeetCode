bool predictTheWinner(int* nums, int numsSize) {
    int dp[20];
    
    for (int i = 0; i < numsSize; i++) {
        dp[i] = nums[i];
    }
    
    for (int len = 2; len <= numsSize; len++) {
        for (int i = 0; i <= numsSize - len; i++) {
            int j = i + len - 1;
            int pickFirst = nums[i] - dp[i + 1];
            int pickLast = nums[j] - dp[i];
            dp[i] = pickFirst > pickLast ? pickFirst : pickLast;
        }
    }
    
    return dp[0] >= 0;
}
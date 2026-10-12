int maxSum(int* nums, int numsSize, int k) {
    int counts[32] = {0};
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < 31; j++) {
            if (nums[i] & (1 << j)) {
                counts[j]++;
            }
        }
    }
    
    long long total = 0;
    int MOD = 1000000007;
    
    for (int i = 0; i < k; i++) {
        long long val = 0;
        for (int j = 0; j < 31; j++) {
            if (counts[j] > 0) {
                val |= (1LL << j);
                counts[j]--;
            }
        }
        long long val_sq = (val * val) % MOD;
        total = (total + val_sq) % MOD;
    }
    
    return (int)total;
}
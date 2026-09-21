long long* resultArray(int* nums, int numsSize, int k, int* returnSize) {
    long long* res = (long long*)calloc(k, sizeof(long long));
    *returnSize = k;
    long long freq[10] = {0};
    
    for (int i = 0; i < numsSize; i++) {
        long long next_freq[10] = {0};
        long long val = nums[i] % k;
        
        for (int j = 0; j < k; j++) {
            if (freq[j] > 0) {
                next_freq[(j * val) % k] += freq[j];
            }
        }
        
        next_freq[val]++;
        
        for (int j = 0; j < k; j++) {
            freq[j] = next_freq[j];
            res[j] += freq[j];
        }
    }
    
    return res;
}
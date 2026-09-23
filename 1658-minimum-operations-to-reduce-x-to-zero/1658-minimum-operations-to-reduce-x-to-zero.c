int minOperations(int* nums, int numsSize, int x) {
    long long total_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }
    
    long long target = total_sum - x;
    if (target < 0) return -1;
    if (target == 0) return numsSize;

    int max_len = -1;
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        current_sum += nums[right];
        
        while (current_sum > target && left <= right) {
            current_sum -= nums[left];
            left++;
        }
        
        if (current_sum == target) {
            if (right - left + 1 > max_len) {
                max_len = right - left + 1;
            }
        }
    }
    
    return max_len == -1 ? -1 : numsSize - max_len;
}
int cmp(const void *a, const void *b) {
    int abs_a = abs(*(int*)a);
    int abs_b = abs(*(int*)b);
    return abs_a - abs_b;
}

long long maxAlternatingSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    long long score = 0;
    int half = numsSize / 2;
    
    for (int i = 0; i < half; i++) {
        score -= (long long)nums[i] * nums[i];
    }
    
    for (int i = half; i < numsSize; i++) {
        score += (long long)nums[i] * nums[i];
    }
    
    return score;
}
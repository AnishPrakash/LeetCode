int firstStableIndex(int* nums, int numsSize, int k) {
    int suff_min[numsSize];
    suff_min[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        suff_min[i] = nums[i] < suff_min[i + 1] ? nums[i] : suff_min[i + 1];
    }
    
    int pref_max = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > pref_max) {
            pref_max = nums[i];
        }
        if (pref_max - suff_min[i] <= k) {
            return i;
        }
    }
    
    return -1;
}
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int min_val = 101;
    int max_val = 0;
    int present[105] = {0};
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
        present[nums[i]] = 1;
    }
    
    int* result = (int*)malloc(105 * sizeof(int));
    *returnSize = 0;
    
    for (int i = min_val + 1; i < max_val; i++) {
        if (!present[i]) {
            result[(*returnSize)++] = i;
        }
    }
    
    return result;
}
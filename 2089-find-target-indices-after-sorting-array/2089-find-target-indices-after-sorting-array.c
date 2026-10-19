int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    int less_count = 0;
    int target_count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < target) {
            less_count++;
        } else if (nums[i] == target) {
            target_count++;
        }
    }
    
    *returnSize = target_count;
    int* result = (int*)malloc(target_count * sizeof(int));
    
    for (int i = 0; i < target_count; i++) {
        result[i] = less_count + i;
    }
    
    return result;
}
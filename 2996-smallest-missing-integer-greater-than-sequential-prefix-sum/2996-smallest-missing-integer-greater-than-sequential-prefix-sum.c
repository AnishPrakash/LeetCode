int missingInteger(int* nums, int numsSize) {
    int sum = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
        } else {
            break;
        }
    }
    
    while (1) {
        int found = 0;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == sum) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            return sum;
        }
        sum++;
    }
}
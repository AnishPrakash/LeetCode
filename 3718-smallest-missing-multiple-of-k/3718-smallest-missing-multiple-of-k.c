int missingMultiple(int* nums, int numsSize, int k) {
    int target = k;
    while(1) {
        int found = 0;
        for(int i = 0; i < numsSize; i++) {
            if(nums[i] == target) {
                found = 1;
                break;
            }
        }
        if(!found) {
            return target;
        }
        target += k;
    }
}
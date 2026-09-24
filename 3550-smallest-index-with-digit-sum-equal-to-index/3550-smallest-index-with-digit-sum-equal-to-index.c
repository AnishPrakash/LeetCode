int smallestIndex(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        int temp = nums[i];
        
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        
        if (sum == i) {
            return i;
        }
    }
    return -1;
}
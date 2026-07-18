int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findGCD(int* nums, int numsSize) {
    int min_val = nums[0];
    int max_val = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }
    
    return gcd(min_val, max_val);
}
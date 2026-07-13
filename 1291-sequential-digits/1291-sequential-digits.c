int* sequentialDigits(int low, int high, int* returnSize) {
    int* result = malloc(36 * sizeof(int));
    *returnSize = 0;
    
    for (int len = 2; len <= 9; ++len) {
        for (int start = 1; start <= 10 - len; ++start) {
            int num = 0;
            for (int i = 0; i < len; ++i) {
                num = num * 10 + (start + i);
            }
            if (num >= low && num <= high) {
                result[(*returnSize)++] = num;
            }
        }
    }
    
    return result;
}
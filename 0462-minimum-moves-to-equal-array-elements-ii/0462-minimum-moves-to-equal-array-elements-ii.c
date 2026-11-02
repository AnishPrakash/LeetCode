int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    long long moves = 0;
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        moves += ((long long)nums[right] - nums[left]);
        left++;
        right--;
    }
    return (int)moves;
}
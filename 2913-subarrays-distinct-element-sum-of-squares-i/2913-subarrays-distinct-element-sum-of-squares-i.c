int sumCounts(int* nums, int numsSize) {
    int total_sum = 0;

    for (int i = 0; i < numsSize; i++) {
        int seen[101] = {0};
        int distinct_count = 0;

        for (int j = i; j < numsSize; j++) {
            if (!seen[nums[j]]) {
                seen[nums[j]] = 1;
                distinct_count++;
            }
            total_sum += distinct_count * distinct_count;
        }
    }

    return total_sum;
}
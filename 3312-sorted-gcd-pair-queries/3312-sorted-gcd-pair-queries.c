#include <stdlib.h>

int* gcdValues(int* nums, int numsSize, long long* queries, int queriesSize, int* returnSize) {
    int max_val = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }

    int* freq = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    long long* exact = (long long*)calloc(max_val + 1, sizeof(long long));
    for (int i = 1; i <= max_val; i++) {
        long long c = 0;
        for (int j = i; j <= max_val; j += i) {
            c += freq[j];
        }
        exact[i] = c * (c - 1) / 2;
    }

    for (int i = max_val; i >= 1; i--) {
        for (int j = 2 * i; j <= max_val; j += i) {
            exact[i] -= exact[j];
        }
    }

    long long* prefix = (long long*)calloc(max_val + 1, sizeof(long long));
    for (int i = 1; i <= max_val; i++) {
        prefix[i] = prefix[i - 1] + exact[i];
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        long long q = queries[i];
        int low = 1, high = max_val;
        int res = max_val;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (prefix[mid] > q) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = res;
    }

    free(freq);
    free(exact);
    free(prefix);

    return ans;
}
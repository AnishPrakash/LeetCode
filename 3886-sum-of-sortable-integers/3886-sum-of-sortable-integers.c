#include <stdlib.h>

long long sortableIntegers(int* nums, int numsSize) {
    int* P = (int*)malloc(numsSize * sizeof(int));
    int* S = (int*)malloc(numsSize * sizeof(int));
    int* drops = (int*)malloc(numsSize * sizeof(int));

    P[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        P[i] = P[i-1] > nums[i] ? P[i-1] : nums[i];
    }

    S[numsSize-1] = nums[numsSize-1];
    for (int i = numsSize - 2; i >= 0; i--) {
        S[i] = S[i+1] < nums[i] ? S[i+1] : nums[i];
    }

    drops[0] = 0;
    for (int i = 1; i < numsSize; i++) {
        drops[i] = drops[i-1] + (nums[i-1] > nums[i] ? 1 : 0);
    }

    long long ans = 0;
    for (int k = 1; k <= numsSize; k++) {
        if (numsSize % k != 0) continue;
        int valid = 1;
        for (int j = 0; j < numsSize; j += k) {
            int L = j;
            int R = j + k - 1;
            int C = drops[R] - drops[L];
            if (!(C == 0 || (C == 1 && nums[R] <= nums[L]))) {
                valid = 0;
                break;
            }
            if (R < numsSize - 1 && P[R] > S[R+1]) {
                valid = 0;
                break;
            }
        }
        if (valid) ans += k;
    }

    free(P);
    free(S);
    free(drops);
    return ans;
}
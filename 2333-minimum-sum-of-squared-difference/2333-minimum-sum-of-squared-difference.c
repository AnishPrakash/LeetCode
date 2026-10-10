long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2) {
    long long k = (long long)k1 + k2;
    int diff_counts[100001] = {0};
    int max_diff = 0;
    long long total_diff = 0;

    for (int i = 0; i < nums1Size; i++) {
        int diff = abs(nums1[i] - nums2[i]);
        diff_counts[diff]++;
        if (diff > max_diff) {
            max_diff = diff;
        }
        total_diff += diff;
    }

    if (total_diff <= k) {
        return 0;
    }

    for (int i = max_diff; i > 0 && k > 0; i--) {
        if (diff_counts[i] > 0) {
            long long reduce = k < diff_counts[i] ? k : diff_counts[i];
            diff_counts[i] -= reduce;
            diff_counts[i - 1] += reduce;
            k -= reduce;
        }
    }

    long long ans = 0;
    for (long long i = 1; i <= max_diff; i++) {
        if (diff_counts[i] > 0) {
            ans += (long long)diff_counts[i] * i * i;
        }
    }
    
    return ans;
}
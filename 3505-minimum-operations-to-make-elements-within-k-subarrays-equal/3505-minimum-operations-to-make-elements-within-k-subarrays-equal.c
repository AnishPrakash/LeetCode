#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare_ll(const void *a, const void *b) {
    long long arg1 = *(const long long *)a;
    long long arg2 = *(const long long *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

typedef struct {
    int *tree;
    long long *sum_tree;
    int size;
} FenwickTree;

static void fenwick_add(FenwickTree *ft, int idx, int val_count, long long val_sum) {
    for (; idx <= ft->size; idx += idx & -idx) {
        ft->tree[idx] += val_count;
        ft->sum_tree[idx] += val_sum;
    }
}

static int fenwick_query_count(FenwickTree *ft, int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += ft->tree[idx];
    }
    return sum;
}

static long long fenwick_query_sum(FenwickTree *ft, int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += ft->sum_tree[idx];
    }
    return sum;
}

static int fenwick_find_kth(FenwickTree *ft, int k) {
    int idx = 0;
    for (int step = 1 << 18; step > 0; step >>= 1) {
        if (idx + step <= ft->size && ft->tree[idx + step] < k) {
            idx += step;
            k -= ft->tree[idx];
        }
    }
    return idx + 1;
}

static int lower_bound(long long *arr, int n, long long val) {
    int l = 0, r = n - 1, ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= val) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

long long minOperations(int* nums, int numsSize, int x, int k) {
    long long *unique_vals = (long long *)malloc(sizeof(long long) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        unique_vals[i] = nums[i];
    }
    qsort(unique_vals, numsSize, sizeof(long long), compare_ll);

    int u_count = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (i == 0 || unique_vals[i] != unique_vals[i - 1]) {
            unique_vals[u_count++] = unique_vals[i];
        }
    }

    int *ranks = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        ranks[i] = lower_bound(unique_vals, u_count, nums[i]) + 1;
    }

    FenwickTree ft;
    ft.size = u_count;
    ft.tree = (int *)calloc(u_count + 1, sizeof(int));
    ft.sum_tree = (long long *)calloc(u_count + 1, sizeof(long long));

    int num_windows = numsSize - x + 1;
    long long *cost = (long long *)malloc(sizeof(long long) * num_windows);

    for (int i = 0; i < x - 1; ++i) {
        fenwick_add(&ft, ranks[i], 1, nums[i]);
    }

    int med_idx = (x + 1) / 2;

    for (int i = x - 1; i < numsSize; ++i) {
        fenwick_add(&ft, ranks[i], 1, nums[i]);

        int start_idx = i - x + 1;
        int med_rank = fenwick_find_kth(&ft, med_idx);
        long long median = unique_vals[med_rank - 1];

        int count_left = fenwick_query_count(&ft, med_rank);
        long long sum_left = fenwick_query_sum(&ft, med_rank);
        long long cost_left = (long long)count_left * median - sum_left;

        int count_right = x - count_left;
        long long total_sum = fenwick_query_sum(&ft, u_count);
        long long sum_right = total_sum - sum_left;
        long long cost_right = sum_right - (long long)count_right * median;

        cost[start_idx] = cost_left + cost_right;

        fenwick_add(&ft, ranks[start_idx], -1, -nums[start_idx]);
    }

    long long INF = 1e18;
    long long *dp = (long long *)malloc(sizeof(long long) * (numsSize + 1));
    long long *next_dp = (long long *)malloc(sizeof(long long) * (numsSize + 1));

    for (int i = 0; i <= numsSize; ++i) {
        dp[i] = 0;
    }

    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i <= numsSize; ++i) {
            next_dp[i] = INF;
        }
        for (int i = j * x; i <= numsSize; ++i) {
            long long pick = dp[i - x] + cost[i - x];
            long long skip = next_dp[i - 1];
            next_dp[i] = (pick < skip) ? pick : skip;
        }
        long long *tmp = dp;
        dp = next_dp;
        next_dp = tmp;
    }

    long long result = dp[numsSize];

    free(unique_vals);
    free(ranks);
    free(ft.tree);
    free(ft.sum_tree);
    free(cost);
    free(dp);
    free(next_dp);

    return result;
}
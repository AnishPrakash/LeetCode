#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int find_idx(int* S, int M, int val) {
    int l = 0, r = M - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (S[mid] == val) return mid;
        if (S[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* S = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        S[i] = nums[i];
    }
    
    qsort(S, n, sizeof(int), cmp);
    
    int M = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || S[i] != S[i - 1]) {
            S[M++] = S[i];
        }
    }
    
    int* up = (int*)malloc(M * 18 * sizeof(int));
    int r = 0;
    for (int i = 0; i < M; i++) {
        while (r + 1 < M && S[r + 1] - S[i] <= maxDiff) {
            r++;
        }
        up[i * 18 + 0] = r;
    }
    
    for (int j = 1; j < 18; j++) {
        for (int i = 0; i < M; i++) {
            up[i * 18 + j] = up[up[i * 18 + j - 1] * 18 + j - 1];
        }
    }
    
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];
        
        if (u == v) {
            ans[i] = 0;
            continue;
        }
        if (nums[u] == nums[v]) {
            ans[i] = 1;
            continue;
        }
        
        int valU = nums[u];
        int valV = nums[v];
        if (valU > valV) {
            int tmp = valU;
            valU = valV;
            valV = tmp;
        }
        
        int a = find_idx(S, M, valU);
        int b = find_idx(S, M, valV);
        
        if (up[a * 18 + 17] < b) {
            ans[i] = -1;
            continue;
        }
        
        int steps = 0;
        for (int k = 17; k >= 0; k--) {
            if (up[a * 18 + k] < b) {
                a = up[a * 18 + k];
                steps += (1 << k);
            }
        }
        ans[i] = steps + 1;
    }
    
    free(S);
    free(up);
    return ans;
}
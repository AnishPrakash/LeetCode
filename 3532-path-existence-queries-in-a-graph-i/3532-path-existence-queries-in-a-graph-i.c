bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* g = (int*)malloc(n * sizeof(int));
    int cnt = 0;
    g[0] = cnt;
    
    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] > maxDiff) {
            cnt++;
        }
        g[i] = cnt;
    }
    
    bool* ans = (bool*)malloc(queriesSize * sizeof(bool));
    
    for (int i = 0; i < queriesSize; i++) {
        ans[i] = (g[queries[i][0]] == g[queries[i][1]]);
    }
    
    *returnSize = queriesSize;
    free(g);
    
    return ans;
}
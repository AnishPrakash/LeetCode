int* sumAndMultiply(char * s, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int m = strlen(s);
    int MOD = 1000000007;

    int* pow10 = (int*)malloc((m + 1) * sizeof(int));
    int* count = (int*)malloc((m + 1) * sizeof(int));
    int* val = (int*)malloc((m + 1) * sizeof(int));
    long long* prefSum = (long long*)malloc((m + 1) * sizeof(long long));

    pow10[0] = 1;
    count[0] = 0;
    val[0] = 0;
    prefSum[0] = 0;

    for (int i = 0; i < m; i++) {
        pow10[i + 1] = (int)(((long long)pow10[i] * 10) % MOD);
        int d = s[i] - '0';
        count[i + 1] = count[i];
        val[i + 1] = val[i];
        prefSum[i + 1] = prefSum[i];

        if (d > 0) {
            count[i + 1]++;
            val[i + 1] = (int)(((long long)val[i] * 10 + d) % MOD);
            prefSum[i + 1] += d;
        }
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int l = queries[i][0];
        int r = queries[i][1];

        int k = count[r + 1] - count[l];
        long long x = val[r + 1] - ((long long)val[l] * pow10[k]) % MOD;
        if (x < 0) {
            x += MOD;
        }

        long long sum = prefSum[r + 1] - prefSum[l];
        ans[i] = (int)((x * (sum % MOD)) % MOD);
    }

    free(pow10);
    free(count);
    free(val);
    free(prefSum);

    return ans;
}
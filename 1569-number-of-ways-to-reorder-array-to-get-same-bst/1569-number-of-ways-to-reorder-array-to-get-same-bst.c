long long table[1005][1005];
long long MOD = 1000000007;
int tableBuilt = 0;

void buildTable() {
    if (tableBuilt) return;
    for (int i = 0; i <= 1000; i++) {
        table[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
        }
    }
    tableBuilt = 1;
}

long long solve(int* arr, int n) {
    if (n <= 1) return 1;
    
    int* left = (int*)malloc(n * sizeof(int));
    int* right = (int*)malloc(n * sizeof(int));
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[0]) {
            left[l++] = arr[i];
        } else {
            right[r++] = arr[i];
        }
    }
    
    long long res = table[l + r][l];
    res = (res * solve(left, l)) % MOD;
    res = (res * solve(right, r)) % MOD;
    
    free(left);
    free(right);
    
    return res;
}

int numOfWays(int* nums, int numsSize) {
    buildTable();
    long long ans = solve(nums, numsSize);
    return (ans - 1 + MOD) % MOD;
}
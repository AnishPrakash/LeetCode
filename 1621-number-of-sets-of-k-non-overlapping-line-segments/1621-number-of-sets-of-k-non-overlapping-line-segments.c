int numberOfSets(int n, int k) {
    long long res = 1;
    int N = n + k - 1;
    int K = 2 * k;
    long long MOD = 1000000007;
    
    for (int i = 1; i <= K; i++) {
        res = (res * (N - i + 1)) % MOD;
        
        long long base = i;
        long long exp = MOD - 2;
        long long inv = 1;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                inv = (inv * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        
        res = (res * inv) % MOD;
    }
    
    return res;
}